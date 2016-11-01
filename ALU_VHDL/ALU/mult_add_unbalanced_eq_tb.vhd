library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;


entity mult_add_unbalanced_tb is
end mult_add_unbalanced_tb;



architecture testbench of mult_add_unbalanced_tb is


	signal CLK : std_logic := '1';
 	signal RST : std_logic :=  '1';
 	signal IN_RDY, IN_RDY_MULT, IN_RDY_SUM, IN_RDY_FINAL  : std_logic := '0';
 	signal OUT_RDY, OUT_RDY_MULT, OUT_RDY_SUM, OUT_RDY_FINAL : std_logic := '0';
 	signal X, Y, A, B : std_logic_vector(31 downto 0) := (others => '0');
 	signal FUNC_MULT, FUNC_ADD, FUNC_FINAL_ADD  :  std_logic_vector(7 downto 0) := (others => '0');
 	signal RESULT_MULT, RESULT_SUM, RESULT_FINAL  : std_logic_vector(63 downto 0) := (others => '0');
	constant half_period : time := 5 ns;
	constant full_period : time := half_period * 2;


	begin
	FUNC_MULT <= OPCODE_MULT;
	FUNC_ADD <= OPCODE_ADD_SUB;
	FUNC_FINAL_ADD <= OPCODE_ADD_SUB;

	uut : entity work.mult_add_unbalanced_eq
		generic map (32)
		port map(	clk => CLK,
					rst => RST,
					in_rdy => IN_RDY,
					in_rdy_mult => IN_RDY_MULT, 
					out_rdy_mult => OUT_RDY_MULT,
					in_rdy_sum => IN_RDY_SUM, 
					out_rdy_sum => OUT_RDY_SUM,
					in_rdy_final => IN_RDY_FINAL,
					out_rdy_final => OUT_RDY_FINAL,
					x => X,
					y => Y,
					a => A,
					b => B,
					opcode1 => FUNC_MULT,
					opcode2 => FUNC_ADD,
					opcode3 => FUNC_FINAL_ADD,
					X_TIMES_Y => RESULT_MULT,
					A_PLUS_B => RESULT_SUM,
					X_TIMES_Y_PLUS_A_PLUS_B => RESULT_FINAL);

	--------------------------------------------------------------
	-- Clock gen
	--------------------------------------------------------------
	clock_gen : process is
	begin
		wait for half_period;
		clk <= '1'; 
		wait for half_period;
		clk <= '0'; 
	end process;


	--------------------------------------------------------------
	-- Test file processing
	--------------------------------------------------------------
	stm_test : process is
		variable file_line 	: line;
		variable data 		: std_logic_vector(131 downto 0);
		file 	test_file	: text open read_mode is "C:\Modeltech_pe_edu_10.4a\ALU\difference_of_products_data";
	begin

		------------------------------------------------------------------------------------------------------------------------
		-- Read inputs from hex -> std_logic_vector -> process-> alu(instruction(71 downto 64), instruc(63-32), instruc(31, 0);
		-------------------------------------------------------------------------------------------------------------------------
		IN_RDY <= '0';
		X <= (others => '0');
		Y <= (others => '0');
		A <= (others => '0');
		B <= (others => '0');
		RST <= '1';
		wait for full_period;
		RST <= '0';
		wait for 10 * full_period;
		wait for (9 ns);
		while not endfile(test_file) loop
			readline(test_file, file_line);
			HREAD(file_line, data);
			IN_RDY <= '1';
			X <= data(31 downto 0);
			Y <= data(63 downto 32);
			A <= data(95 downto 64);
			B <= data(127 downto 96);
			--IN_RDY <= '1';
			wait for  full_period;
		end loop; 
		wait;
	end process;

end testbench;