
library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;


entity math_expression_3_tb is
end math_expression_3_tb;



architecture testbench of math_expression_3_tb is
component math_expression_3 is
		generic(data_width  : 	integer := 32);
		port(	
			clk     			: in std_logic;
			rst     			: in std_logic;
			in_rdy				: in std_logic;
			in_rdy_mult1 		: inout std_logic;
			in_rdy_mult2 	    : inout std_logic;
			out_rdy 		 	: out std_logic;
			out_rdy_mult1   	: buffer std_logic;
			out_rdy_mult2   	: buffer std_logic;
			in_rdy_sum 			: inout std_logic;
			out_rdy_sum  		: buffer std_logic;
			x	   	        	: in std_logic_vector(31 downto 0);
			y	    	    	: in std_logic_vector(31 downto 0);
			a 					: in std_logic_vector(31 downto 0);
			b 					: in std_logic_vector(31 downto 0);
			MULT1	    		: in std_logic_vector(7 downto 0);
			MULT2         		: in std_logic_vector(7 downto 0);
			SUM 				: in std_logic_vector(7 downto 0);
			PRODUCT_x_y	    	: buffer std_logic_vector(63 downto 0);
			PRODUCT_a_b       	: buffer std_logic_vector(63 downto 0);
			Result	    		: out std_logic_vector(63 downto 0));
end component; 

	signal CLK : std_logic;
 	signal RST : std_logic :=  '1';
 	signal IN_RDY, IN_RDY_MULT1, IN_RDY_MULT2, IN_RDY_SUM  : std_logic := '0';
 	signal OUT_RDY, OUT_RDY_MULT1, OUT_RDY_MULT2, OUT_RDY_SUM  : std_logic;
 	signal X, Y, A, B : std_logic_vector(31 downto 0);
 	signal FUNC_CODE1, FUNC_CODE2, FUNC_CODE3  :  std_logic_vector(7 downto 0);
 	signal PRODUCT_MULTIPLIER1, PRODUCT_MULTIPLIER2, Result  : std_logic_vector(63 downto 0);
	


	begin
	
	uut : math_expression_3 
		generic map (32)
		port map(	clk => CLK,   	
					rst => RST,
					in_rdy => IN_RDY,
					in_rdy_mult1 => IN_RDY_MULT1,
					in_rdy_mult2 => IN_RDY_MULT2,
					out_rdy => OUT_RDY,
					out_rdy_mult1 => OUT_RDY_MULT1,
					out_rdy_mult2 => OUT_RDY_MULT2,
					in_rdy_sum    =>  IN_RDY_SUM, 
					out_rdy_sum   =>  OUT_RDY_SUM, 
					x => X,  
					y => Y,
					a => A, 
					b => B, 
					MULT1 => FUNC_CODE1,
					MULT2 => FUNC_CODE2,
					SUM   => FUNC_CODE3,  
					PRODUCT_x_y => PRODUCT_MULTIPLIER1,
					PRODUCT_a_b => PRODUCT_MULTIPLIER2, 
					Result => Result);

	--------------------------------------------------------------
	-- Clock gen
	--------------------------------------------------------------
	clock_gen : process is
	begin
		wait for 5 ns;
		clk <= '1'; 
		wait for 5 ns;
		clk <= '0'; 
	end process;


	--------------------------------------------------------------
	-- Test file processing
	--------------------------------------------------------------
	stm_test : process is
		variable file_line 	: line;
		variable data 		: std_logic_vector(67 downto 0);
		file 	test_file	: text open read_mode is "C:\Modeltech_pe_edu_10.4a\ALU\math_expr_3_data";
	begin

		------------------------------------------------------------------------------------------------------------------------
		-- Read inputs from hex -> std_logic_vector -> process-> alu(instruction(71 downto 64), instruc(63-32), instruc(31, 0);
		-------------------------------------------------------------------------------------------------------------------------
		RST <= '1';
		--wait for 9 ns;
		--wait for 100 ns;
		FUNC_CODE1 <= OPCODE_MULT;
		FUNC_CODE2 <= OPCODE_MULT;
		FUNC_CODE3 <= OPCODE_ADD_SUB;
		wait for 5 ns;
		RST <= '0';
		wait for 10 ns;
		while not endfile(test_file) loop
			readline(test_file, file_line);
			HREAD(file_line, data);
   			--RST <= data(67);
   			IN_RDY <= data(64);
			X <= data(31 downto 0);
			Y <= data(63 downto 32);
			A <= data(31 downto 0);
			B <= data(63 downto 32);
			wait for 10 ns;
		end loop; 
		wait;
	end process;

end testbench;

--https://www.youtube.com/watch?v=dy3-QZLTpbQ
--https://github.com/kanto-player/kanto/blob/master/dft_tb.vhd
--http://serverfault.com/questions/478678/how-to-speed-up-file-transfer-from-server-to-server-over-the-internet
--http://electronics.stackexchange.com/questions/83955/how-do-i-save-a-waveform-from-modelsim-for-later-opening-viewing