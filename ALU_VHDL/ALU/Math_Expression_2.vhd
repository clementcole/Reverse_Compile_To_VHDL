library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;
use work.Components.all;


entity math_expression_2 is
		generic(data_width  : 	integer := 32);
		port(	
			clk     		: in std_logic;
			A	   	        : in std_logic_vector(31 downto 0);
			B	    	    : in std_logic_vector(31 downto 0);
			C 	    	    : in std_logic_vector(31 downto 0);
			D 	    	    : in std_logic_vector(31 downto 0);
			X           	: in std_logic_vector(31 downto 0);
			Y           	: in std_logic_vector(31 downto 0);
			go				: in std_logic;
			rst     		: in std_logic;
			--go_add1			: in std_logic;
			--go_add2			: in std_logic;
			--go_mult1 		: in std_logic;
			--go_mult2 	    : in std_logic;
			--go_add3     	: in std_logic;
			--done_add1   	: out std_logic;
			--done_add2  	    : out std_logic;
			--done_mult1   	: out std_logic;
			--done_mult2   	: out std_logic;
			done		 	: out std_logic;
			OP1	    	 	: in std_logic_vector(7 downto 0);
			OP2         	: in std_logic_vector(7 downto 0);
			OP3         	: in std_logic_vector(7 downto 0);
			OP4	    	: in std_logic_vector(7 downto 0);
			OP5	    	: in std_logic_vector(7 downto 0);
			AB	    	: out std_logic_vector(63 downto 0);
			CD	    	: out std_logic_vector(63 downto 0);
			XAB	    	: out std_logic_vector(63 downto 0);
			YCD	    	: out std_logic_vector(63 downto 0);
			Result	    : out std_logic_vector(63 downto 0));
end math_expression_2;

architecture nodes of math_expression_2 is
	--Equation is X(A + B) + Y(C + D)
	signal inputA, inputB, inputC, inputD, inputX, inputY, inputAB, inputCD, inputXAB, inputYCD : std_logic_vector(31 downto 0);
	signal rstADD1, rstADD2, rstMULT1, rstMULT2, rstSUB1	: std_logic;
	signal O1, O2, O3, O4, O5			: std_logic_vector(7 downto 0);
	signal output_AB, output_CD, output_XAB, output_YCD, output_Final : std_logic_vector(63 downto 0);
	--signal ResultTemp1, ResultTemp2, ResultTemp3, ResultTemp4, ResultTemp5, ResultTemp6 : std_logic_vector(63 downto 0);
	signal clock_0, clock_1, clock_2,   go_12, go_34, go_5,  done_1, done_2, done_3, done_4,  done_5,  reset : std_logic;
	--signal count : integer range 0 to 2 ** data_width;
	--type SOLVE_FSM is (IDLE, CAB, CCD, CXAB, CYCD, FINISH);
	--signal state: SOLVE_FSM;
	--attribute INIT: string;
	--attribute INIT of state: signal is "IDLE";
	
	component ALU_EXPERIMENT_32 is
	generic(data_width 	:	 	integer := 32);
	port(   
		A 		:		in std_logic_vector(31 downto 0); --input operands
		B		: 		in std_logic_vector(31 downto 0);
		clk		:               in std_logic;
		rst     :     in std_logic;
		input_ready	:		in std_logic;
		output_ready	:		out std_logic;
		Operation	: 		in std_logic_vector(7 downto 0); --select operation
		Result 		: 		out std_logic_vector(63 downto 0));
	end component;


begin
			
	--process(clk, go ) is 
	--begin 
	--if(clk = '1' and go = '1') then 
			inputA <= A;
			inputB <= B;
			inputC <= C;
			inputD <= D;
			inputX <= X;
			inputY <= Y;
			AB <= output_AB;
			CD <= output_CD;
			XAB <= output_XAB;
			YCD <= output_YCD;
			Result <= output_Final;


			inputAB <= output_AB(31 downto 0);
			inputCD <= output_CD(31 downto 0);
			inputXAB <= output_XAB(31 downto 0);
			inputYCD <= output_YCD(31 downto 0);
			---O1 <= OP1;
			--O2 <= OPCODE_ADD_SUB;
			--O3 <= OPCODE_MULT;
			--O4 <= OPCODE_MULT;
			--O5 <= OPCODE_ADD_SUB;
			--
			--Nodes 1 and 2
			--
			--wait until rising_edge(clk);
			--go_add1 <= go;
			--go_add2 <= go;

			--wait until rising_edge(clk);
			--go_mult1 <= done_add1;
			--go_mult2 <= done_add2;
			

			--done_34 <= done_mult1;
			--wait until rising_edge(clk);
			--go_add3 <= done_34;

			go_12 <= go;
			go_34 <= done_1 and done_2;
			go_5 <= done_3 and done_4;
			done <= done_5;
			--done <= done_add3;
			--rstADD1 <= rst;
			--rstADD2 <= rst;
			--rstMULT1 <= rst;
			--rstMULT2 <= rst;
			--rstSUB1 <= rst;
			--(A + B)
	--end if;
	--end process;
	--(A + B)
	ADD1 : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
		A 		=>      A,
		B		=> 		B,
		clk		=>      clk,
		rst     =>      rst, 
		input_ready		=>	go_12,
		output_ready	=>	done_1,
		Operation	=>      OP1,
		Result 		=>   	output_AB
	);

	--(C + D)
	ADD2 : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
		A 		=>      C,
		B		=> 		D,
		clk		=>      clk,
		rst     =>      rst, 
		input_ready		=>	go_12,
		output_ready	=>  done_2,
		Operation	=>      OP2,
		Result 		=>   	output_CD
	);

	--X(A + B)
	MULT1 : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
		A 		=>      X,
		B		=> 	inputAB,
		clk		=>      clk,
		rst     =>   rst,
		input_ready	=>	go_34,
		output_ready	=>	done_3,
		Operation	=>      OP3,
		Result 		=>   	output_XAB
	
	);

	--Y(C + D)
	MULT2 : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
		A 		=>      Y,
		B		=> 	inputCD,
		clk		=>      clk,
		rst     =>  	rst,  
		input_ready	=>	go_34,
		output_ready	=>	done_4,
		Operation	=>      OP4,
		Result 		=>   	output_YCD
	
	);

	
	--X(A + B) + Y(C + D)
	ADD : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
		A 		=>      inputYCD(31 downto 0),
		B		=> 		inputXAB(31 downto 0),
		clk		=>      clk,
		rst     =>     	rst,  
		input_ready	=>	go_5,
		output_ready =>	done_5,
		Operation	=>  OP5,
		Result 		=>  output_Final
		
		);
end nodes;

