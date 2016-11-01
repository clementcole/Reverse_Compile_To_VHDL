library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;



entity ALU_EXPERIMENT_32_TB is
end;

architecture testbench of ALU_EXPERIMENT_32_TB is

	----------------------------------------------
	-- ALU COMPONENT
	----------------------------------------------
	component ALU_EXPERIMENT_32 is
	generic(data_width 	:	 	integer := 32);
	port(   
		A 		:		in std_logic_vector(31 downto 0); --input operands
		B		: 		in std_logic_vector(31 downto 0);
		clk		:       in std_logic;
		rst     :     	in std_logic;
		input_ready	:		in std_logic;
		output_ready	:	out std_logic;
		Operation	: 		in std_logic_vector(7 downto 0); --select operation
		Result 		: 		out std_logic_vector(63 downto 0));
		--count		:       buffer std_logic_vector(5 downto 1));  --Reg3
	end component;

	----------------------------------------------------------
	-- Signal declarations
	----------------------------------------------------------
	signal A		: std_logic_vector(31 downto 0)  :=  (others => '0');
	signal B		: std_logic_vector(31 downto 0)  :=  (others => '0');
	signal clk		: std_logic := '1';
	signal rst		: std_logic := '1';
	signal input_ready		: std_logic  := '0';
	signal output_ready		: std_logic  := '0';
	signal Operation	: std_logic_vector(7 downto 0)  := OPCODE_IDLE;
	signal Result		: std_logic_vector(63 downto 0) := (others => '0');
	
	constant Period 	: time := 10 ns;
	
	begin
	----------------------------------------------------------
	-- Port mapping
	----------------------------------------------------------
	uut : ALU_EXPERIMENT_32
		generic map(data_width => 32)
		port map(A => A, B => B, clk => clk,   rst => rst,  input_ready => input_ready, output_ready => output_ready, Operation => Operation, Result => Result);	
	
		
	--------------------------------------------------------------
	-- Clock gen
	--------------------------------------------------------------
	clock_gen : process is
	begin
	    clk <= '1'; wait for (period / 2);
	    clk <= '0'; wait for (period / 2);
	
	end process;

	
	--------------------------------------------------------------
	-- Test file processing
	--------------------------------------------------------------
	stm_test : process is
		variable file_line 	: line;
		variable data 		: std_logic_vector(75 downto 0);
		file 	test_file	: text open read_mode is "C:\Modeltech_pe_edu_10.4a\ALU\data_input";
	begin
		
		
		------------------------------------------------------------------------------------------------------------------------
		-- Read inputs from hex -> std_logic_vector -> process-> alu(instruction(71 downto 64), instruc(63-32), instruc(31, 0);
		-------------------------------------------------------------------------------------------------------------------------
		--go <= '1';
		input_ready <= '0';
		--A <= (others => '0');
		--B <= (others => '0');
		rst <= '1'; 
		wait for period;
		rst <= '0';
		wait for (5 * period);
   		--rst <= data(75); wait for period; 
   		--Previous version
		--wait for (10 * period);
		--rst <= '1'; wait for Period;
		--rst <= '0'; wait for Period;
		--wait for (5 * period);
		wait for 10 * Period;
		wait for 9 ns;
		while not endfile(test_file) loop
			readline(test_file, file_line);
			HREAD(file_line, data);
			---Modifications
			--input_ready <= '0';
			--A <= (others => '0');
			--B <= (others => '0');
			--rst <= '1'; wait for period;
			--wait for (5 * period);
   			--rst <= data(75); 
   			--wait for (9 ns); 
   			--input_ready <= data(74);  --1
   			--wait for 1 ns;
			Operation <= data(71 downto 64);
			A        <=  (data(63 downto 32));
			B        <=  (data(31 downto 0));
			--wait for 9 ns;
			input_ready <= '1';
			wait for (10 * Period);
			--rst <= '1';
			--wait for Period * 6;
			--wait for 9 ns;
			--input_ready <= '0';
			--wait for 60 ns;
		end loop; 
		wait;
	end process;
end testbench;

