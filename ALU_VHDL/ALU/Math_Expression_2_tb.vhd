
library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;


entity math_expression_2_tb is
end math_expression_2_tb;



architecture testbench of math_expression_2_tb is

	
	component math_expression_2 is
		generic(data_width  : 	integer := 32);
		port(	clk	     	:  std_logic;
			A	   	 		: in std_logic_vector(31 downto 0);
			B	    		: in std_logic_vector(31 downto 0);
			C 	    		: in std_logic_vector(31 downto 0);
			D 	    		: in std_logic_vector(31 downto 0);
			X           	: in std_logic_vector(31 downto 0);
			Y           	: in std_logic_vector(31 downto 0);
			go				: in std_logic;
			rst     		: in std_logic;
			--go_add1			: inout std_logic;
			--go_add2			: inout std_logic;
			--go_mult1 		: inout std_logic;
			--go_mult2 		: inout std_logic;
			--go_add3     	: inout std_logic;
			--done_add1   	: inout std_logic;
			--done_add2  		: inout std_logic;
			--done_mult1   	: inout std_logic;
			--done_mult2   	: inout std_logic;
			done			: inout std_logic;
			OP1	    		: in std_logic_vector(7 downto 0);
			OP2         	: in std_logic_vector(7 downto 0);
			OP3         	: in std_logic_vector(7 downto 0);
			OP4	    		: in std_logic_vector(7 downto 0);
			OP5	    		: in std_logic_vector(7 downto 0);
			AB	    		: out std_logic_vector(63 downto 0);
			CD	    		: out std_logic_vector(63 downto 0);
			XAB	    		: buffer std_logic_vector(63 downto 0);
			YCD	    		: buffer std_logic_vector(63 downto 0);
			Result	     	: inout std_logic_vector(63 downto 0));
	end component;

	signal clk : std_logic;
 	signal rst : std_logic :=  '1';
	signal A   : std_logic_vector(31 downto 0); 
	signal B   : std_logic_vector(31 downto 0);
	signal C : std_logic_vector(31 downto 0);
	signal D : std_logic_vector(31 downto 0);
	signal X : std_logic_vector(31 downto 0);
	signal Y : std_logic_vector(31 downto 0);
	signal A_plus_B, C_plus_D, X_times_A_plus_B, Y_times_C_plus_D, FinalResult	: std_logic_vector(63 downto 0);
	signal OP1 : std_logic_vector(7 downto 0);
	signal OP2 : std_logic_vector(7 downto 0);
	signal OP3 : std_logic_vector(7 downto 0); 
	signal OP4 : std_logic_vector(7 downto 0);
	signal OP5 : std_logic_vector(7 downto 0);
	signal input_ready_0 : std_logic := '1';
	signal input_ready_node1, input_ready_node2, input_ready_node3, input_ready_node4, input_ready_node5, output_ready_5,  output_ready_node1, output_ready_node2, output_ready_node3, output_ready_node4 : std_logic;
	
	

begin
	
	uut : math_expression_2 
		generic map (32)
		port map(	clk => Clk,   	
				A => A, B => B, C => C, D => D, X => X, Y => Y, 
				go => input_ready_0, rst => rst,
				--go_add1 => input_ready_node1,  go_add2 => input_ready_node2, go_mult1 => input_ready_node3, go_mult2=> input_ready_node4, go_add3=> input_ready_node5, 
				--done_add1 => output_ready_node1, done_add2 => output_ready_node2, done_mult1=>output_ready_node3, done_mult2=> output_ready_node4,  
				done => output_ready_5,
				OP1 => OP1,  OP2 => OP2,  OP3 => OP3,  OP4 => OP4, OP5 => OP5,
				AB => A_plus_B, CD => C_plus_D, XAB => X_times_A_plus_B,  YCD  => Y_times_C_plus_D,		Result => FinalResult);

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
	-- Read DFG CONFIGURATION FILE
	--------------------------------------------------------------
	stm_test : process is
		variable file_line 	: line;
		variable data 		: std_logic_vector(191 downto 0);
		file 	test_file	: text open read_mode is "C:\Modeltech_pe_edu_10.4a\ALU\nodes_inputs";

	begin
		wait for 15 ns;
		rst <= '0';
		OP1 <= OPCODE_ADD_SUB;
		OP2 <= OPCODE_ADD_SUB;
		OP3 <= OPCODE_MULT;
		OP4 <= OPCODE_MULT;
		OP5 <= OPCODE_ADD_SUB;
		wait for 9 ns;
		while not endfile(test_file) loop
			readline(test_file, file_line);
			HREAD(file_line, data);
			input_ready_0 <= '1';
			A  <= (data(191 downto 160));
			B  <= (data(159 downto 128));
			C  <= (data(127 downto 96));
			D  <= (data(95 downto 64));
			X  <= (data(63 downto 32)); 
			Y  <= (data(31 downto 0)); 
			wait for 15 ns;
			--input_ready_0 <= '0';
		end loop; 
		wait;
	end process;
end testbench;