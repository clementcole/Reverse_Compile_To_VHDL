library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;
--use work.test_output_utils.all;
--use work.floatpoint.all;


entity alu_32_tb is
end;

architecture testbench of alu_32_tb is

	----------------------------------------------
	-- ALU COMPONENT
	----------------------------------------------
	component ALU_MAIN_32 is 
			generic(data_width 	:	 	integer := 32);
			port(   clk 		: 		in std_logic; -- Clock
					reset		: 		in std_logic;
					A 			:		in std_logic_vector(31 downto 0); --input operands
					B			: 		in std_logic_vector(31 downto 0);
					Operation	: 		in std_logic_vector(7 downto 0); --select operation
					Result 		: 		out std_logic_vector(63 downto 0));  --Reg3
	end component;

	----------------------------------------------------------
	-- Signal declarations
	----------------------------------------------------------
	signal clk		: std_logic;
	signal reset		: std_logic;
	signal A		: std_logic_vector(31 downto 0);
	signal B		: std_logic_vector(31 downto 0);
	signal Operation	: std_logic_vector(7 downto 0);
	signal Result		: std_logic_vector(63 downto 0);
	signal Flags 		: unsigned(2 downto 0);
	signal CO		: std_logic;
	constant Period 	: time := 10 ns;
	
	begin
	----------------------------------------------------------
	-- Port mapping
	----------------------------------------------------------
	uut : ALU_MAIN_32
		generic map(data_width => 32)
		port map(clk => clk, reset => reset, A => A , B => B, Operation => Operation,  Result => Result );	
	
		
	--------------------------------------------------------------
	-- Clock gen
	--------------------------------------------------------------
	clock_gen : process is
	begin
		clk <= '1';
		wait for Period/2;
		clk <= '0';
		wait for Period/2;
	end process;


	--------------------------------------------------------------
	-- Test file processing
	--------------------------------------------------------------
	stm_test : process is
		variable file_line 	: line;
		variable data 		: std_logic_vector(71 downto 0);
		file 	test_file	: text open read_mode is "/home/clement/workspace/ALU_VHDL/VHDL-Components/alu/data_input";
	begin

		
		------------------------------------------------------------------------------------------------------------------------
		-- Read inputs from hex -> std_logic_vector -> process-> alu(instruction(71 downto 64), instruc(63-32), instruc(31, 0);
		-------------------------------------------------------------------------------------------------------------------------
		reset <= '0';
		wait for 1 * Period;
		reset <= '1';
		wait for Period;
		reset <= '0';
		while not endfile(test_file) loop
			readline(test_file, file_line);
			HREAD(file_line, data);	
			--test_instruction <= (data);
			Operation <= data(71 downto 64);
			A        <=  (data(63 downto 32));
			B        <=  (data(31 downto 0)); 
			wait for 40 * Period;
			
		end loop; 
		wait;
	end process;
end testbench;

