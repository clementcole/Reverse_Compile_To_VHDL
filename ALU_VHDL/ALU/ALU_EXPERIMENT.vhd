----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:43:13 07/20/2016 
-- Design Name: 
-- Module Name:    alu_main_32 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.NUMERIC_STD.ALL;
library work;
use work.opcodes.all;



entity AlU_EXPERIMENT_32 is
	generic(data_width 	:	 	integer := 32);
	port(   
		A 				:		in std_logic_vector(31 downto 0); --input operands
		B				: 		in std_logic_vector(31 downto 0);
		clk				:       in std_logic;
		rst 			:       in std_logic;
		input_ready		:		in std_logic; 
		output_ready	:		out std_logic;
		Operation		: 		in std_logic_vector(7 downto 0); --select operation
		Result 			: 		out std_logic_vector(63 downto 0));
		--result_rdy      :       out std_logic_vector(17 downto 0));
end;

architecture BEHAVIORAL of ALU_EXPERIMENT_32 is
--------------------------------------
--Signals inputs/outputs temporary
---------------------------------------
signal inputA, inputB 				: std_logic_vector(data_width-1 downto 0);-- := (others => '0');
signal op							: std_logic_vector(7 downto 0);
signal invertB 						: std_logic_vector(31 downto 0);
signal output, temp 				: std_logic_vector(63 downto 0);-- := (others => '0');
signal parallel_load_signals		: std_logic_vector(11 downto 0);
signal EnableDin, EnableDout		: std_logic;
signal A_sign						: std_logic;
signal B_sign						: std_logic;
signal R_sign						: std_logic;
signal input_ready_signal			: std_logic;
signal output_ready_signal 			: std_logic;
signal r_add_sub 	 				: std_logic_vector(32 downto 0);-- 	:= (others => '0');
signal in_ready 					: std_logic_vector(17 downto 0);-- 	:= (others => '0');
signal result_ready					: std_logic_vector(17 downto 0);--		:= (others => '0'); 
signal r_or, r_and, r_xnor, r_nor 	: std_logic_vector(31 downto 0);-- 	:= (others => '0');
signal r_not, r_xor 				: std_logic_vector(31 downto 0);-- 	:= (others => '0');
signal r_sla, r_sra, r_sll 			: std_logic_vector(31 downto 0);-- 	:= (others => '0');
signal r_srl 		 				: std_logic_vector(31 downto 0);--    := (others => '0');
signal r_fadd, r_fsub, r_fmult, r_fdiv 		: std_logic_vector(31 downto 0);-- := (others => '0');
signal r_ror, r_rol 				: std_logic_vector(31 downto 0);--		:= (others => '0');
signal r_div 						: std_logic_vector(31 downto 0);--		:= (others => '0');
signal r_mult						: std_logic_vector(63 downto 0);
signal cin 							: std_logic;
signal cout 						: std_logic;
signal rst_counter              	: std_logic;
signal alu_operation_ready          : std_logic;

--Fifo signals 
signal rd_en_A, rd_en_B             : std_logic := '0';
signal full_fifo_A, full_fifo_B     : std_logic := '0';
signal empty_fifo_A, empty_fifo_B   : std_logic := '0'; 
signal input_ready_A, input_ready_B : std_logic := '0';
--signal dout_A, dout_B   : std_logic_vector(31 downto 0);

	
	component add_sub_reg is
		generic ( bits 	: integer  := 32);
		port (
				A				: in signed(31 downto 0);
				B				: in signed(31 downto 0);
				clk				:       in std_logic;
				rst 			:       in std_logic;
				input_ready : in std_logic;
				output_ready : out std_logic;
			Result 	: out std_logic_vector(32 downto 0));
	end component;
	
	component mult_reg is
		generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(63 downto 0));
	end component;
	
	component or_reg is 	--Completed
		generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component nor_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;


	component and_reg is     --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;


	component xor_reg is     --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component xnor_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component not_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component sll_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;
  
	component srl_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component sla_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component sra_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component ror_reg is    --Completed
	generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component rol_reg is    --Completed
		generic(bits 	:	 	integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	component fmult_reg is   --Completed
		generic(bits : integer := 32);
		port(   
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component;

	--component fp_div_reg is 
	--	generic (bits : integer := 32);
	--	port ( 
	--		A 				:		in std_logic_vector(31 downto 0); --input operands
	--		B				: 		in std_logic_vector(31 downto 0);
	--		clk				:       in std_logic;
	--		rst 			:       in std_logic;
	--		input_ready		:		in std_logic; 
	--		output_ready	:		out std_logic;
	--		Result 			: 		out std_logic_vector(31 downto 0));
	--end component;

	component fadd_reg is  --Completed
		generic (bits : integer := 32);
		port ( 
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component; 

	component fsub_reg is  --Completed
		generic (bits : integer := 32);
		port ( 
			A 				:		in std_logic_vector(31 downto 0); --input operands
			B				: 		in std_logic_vector(31 downto 0);
			clk				:       in std_logic;
			rst 			:       in std_logic;
			input_ready		:		in std_logic; 
			output_ready	:		out std_logic;
			Result 			: 		out std_logic_vector(31 downto 0));
	end component; 
		
	component fifo_32 
 		PORT (
    		clk : IN STD_LOGIC;
    		rst : IN STD_LOGIC;
   			din : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    		wr_en : IN STD_LOGIC;
    		rd_en : IN STD_LOGIC;
    		dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    		full : OUT STD_LOGIC;
    		empty : OUT STD_LOGIC
  	);
	end component;

	



begin	
	input_ready_A <= input_ready;
	input_ready_B <= input_ready;
	alu_operation_ready <= not(empty_fifo_A) and not(empty_fifo_B);
	rd_en_A <= alu_operation_ready;
	rd_en_B <= alu_operation_ready;

	PM_FIFO_32_16_A : fifo_32
		port map(clk => clk, rst => rst, din => A, wr_en => input_ready_A, rd_en => rd_en_A, dout => inputA, full => full_fifo_A, empty => empty_fifo_A );

	PM_FIFO_32_16_B : fifo_32 
		port map(clk => clk, rst => rst, din => B, wr_en => input_ready_B, rd_en => rd_en_B, dout => inputB, full => full_fifo_B, empty => empty_fifo_B );

	PM_ADD_SUB : add_sub_reg 
		generic map (bits => 32)
		port map (A => signed(inputA),  B => signed(inputB), clk => clk, rst => rst, input_ready => in_ready(0), output_ready => result_ready(0), std_logic_vector(Result) => r_add_sub ); 


	PM_MULT : mult_reg
		generic map(bits => 32)
		port map( A => inputA,  B => inputB, clk => clk,  rst => rst, input_ready => in_ready(1), output_ready => result_ready(1), Result => r_mult);


	PM_OR : entity work.or_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(2), output_ready => result_ready(2), Result => r_or);
	
	PM_NOR : nor_reg 
		generic map ( bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(3), output_ready => result_ready(3), Result => r_nor);


	PM_XOR : xor_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(4), output_ready => result_ready(4), Result => r_xor );

	PM_XNOR : xnor_reg  
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(5), output_ready => result_ready(5), Result => r_xnor );

	PM_NOT :  not_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(6), output_ready => result_ready(6), Result => r_not );

	PM_SLL : sll_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(7), output_ready => result_ready(7), Result => r_sll );

	PM_SRL : srl_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(8), output_ready => result_ready(8), Result => r_srl );

	PM_SLA : sla_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(9), output_ready => result_ready(9), Result => r_sla );

	
	PM_SRA : sra_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(10), output_ready => result_ready(10), Result => r_sra );

	PM_ROR : ror_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(11), output_ready => result_ready(11), Result => r_ror );

	
	PM_ROL : rol_reg
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(12), output_ready => result_ready(12), Result => r_rol);

	PM_FADD : fadd_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(13), output_ready => result_ready(13), Result => r_fadd);


	PM_FSUB : fsub_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(14), output_ready => result_ready(14), Result => r_fsub);


	PM_FMULT : fmult_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(15), output_ready => result_ready(15), Result => r_fmult);

	PM_AND : and_reg 
		generic map(bits => 32)
		port map(A => inputA, B => inputB, clk => clk, rst => rst, input_ready => in_ready(16), output_ready => result_ready(16), Result => r_and);

	


	--PM_FDIV : fdiv_reg 
	--	generic map(bits => 32)
	--	port map(A => A, B => B, clk => clk, rst => rst, input_ready => in_ready(17), output_ready => result_ready(17), Result => r_fdiv);

	--PM_DIV : div_reg
	--	generic map(bits => 32)
	--	port map(A => A, B => B, clk => clk, rst => rst, input_ready => in_ready(18), output_ready => result_ready(18), Result => r_fdiv);
	
	

	alu_control : process(clk, Operation,  input_ready, inputA, inputB, rst) is 
	begin 
	--input_ready_A <= input_ready;
	--input_ready_B <= input_ready;
	--rd_en_A <= not(empty_fifo_A and empty_fifo_B);--rd_en_A <= in_ready(0);
	--rd_en_A <= not(empty_fifo_A and empty_fifo_B);--rd_en_B <= in_ready(0);
	--if( rising_edge(clk) and input_ready = '1')  then
	if(rising_edge(clk))  then-- and rst = '0') then 
	  --if(rst = '1') then 
	  if (alu_operation_ready = '0') then 
	  	in_ready <= (others => '0');
	 	--output <= (others => '0');
	  	--result_ready <= (others => '0');
	  	--output_ready <= '0';
	  	--rd_en_A <= not(rst);
	  	--rd_en_B <= not(rst);
	  

	  --elsif( rst = '0' ) then--)and empty_fifo_A = '0' and empty_fifo_B = '0') then 
	  --elsif(not(empty_fifo_A and empty_fifo_B) ) then   
	  elsif(alu_operation_ready = '1' and input_ready = '1') then
	  	--rd_en_A <= '1';
	  	--rd_en_B <= '1';
		case Operation is
			--when OPCODE_RESET => 
			--	output_ready <= '0';	

			when OPCODE_CLEAR => 
				output(63 downto 0) <= (others => '0');
				--in_ready <= (others => '0');
				--result_ready <= (others => '0');


			when OPCODE_IDLE => 
				output(63 downto 0) <= (others => '0'); 
				--in_ready <= (others => '0');


			when OPCODE_ADD_SUB =>  -- 00001
				in_ready(0) <= input_ready;
				--rd_en_A <= '1';
				--rd_en_B <= '1';
				in_ready(17 downto 1) <= (others => '0');
				output(32 downto 0) <= r_add_sub;
				output(63 downto 33) <= (others => '0');
				
				

			when OPCODE_MULT => --output <= r_mult; -- 00011
				in_ready(1) <= input_ready;
				in_ready(0) <= '0';
				in_ready(17 downto 2) <= (others => '0');
				output <= r_mult;
				

			when OPCODE_OR => output(31 downto 0) <= r_or;	--00011
				output(63 downto 32) <= (others => '0');
				in_ready(1 downto 0) <= (others => '0');
				in_ready(2) <= input_ready;
				in_ready(17 downto 3) <= (others => '0');
			
			when OPCODE_NOR => output(31 downto 0) <= r_nor;
				output(63 downto 32) <= (others => '0');
				in_ready(2 downto 0) <= (others => '0');
				in_ready(3) <= input_ready;
				in_ready(17 downto 4) <= (others => '0');
				
			when OPCODE_XOR => output(31 downto 0) <= r_xor;
				output(63 downto 32) <= (others => '0');
				in_ready(3 downto 0) <= (others => '0');
				in_ready(4) <= input_ready;
				in_ready(17 downto 5) <= (others => '0');			


			when OPCODE_XNOR => output(31 downto 0) <= r_xnor;
				output(63 downto 32) <= (others => '0');
				in_ready(4 downto 0) <= (others => '0');
				in_ready(5) <= input_ready;
				in_ready(17 downto 6) <= (others => '0');

			when OPCODE_NOT => output(31 downto 0) <= r_not;
				output(63 downto 32) <= (others => '0');
				in_ready(5 downto 0) <= (others => '0');
				in_ready(6) <= input_ready;
				in_ready(17 downto 7) <= (others => '0');


			when OPCODE_SLL => output(31 downto 0) <= r_sll;
				output(63 downto 32) <= (others => '0');
				in_ready(6 downto 0) <= (others => '0');
				in_ready(7) <= input_ready;
				in_ready(17 downto 8) <= (others => '0');

			
			when OPCODE_SRL => output(31 downto 0) <= r_srl;
				output(63 downto 32) <= (others => '0');
				in_ready(7 downto 0) <= (others => '0');
				in_ready(8) <= input_ready;
				in_ready(17 downto 9) <= (others => '0');	


			when OPCODE_SLA => output(31 downto 0) <= r_sla;
				output(63 downto 32) <= (others => '0');
				in_ready(8 downto 0) <= (others => '0');
				in_ready(9) <= input_ready;
				in_ready(17 downto 10) <= (others => '0');

			when OPCODE_SRA => output(31 downto 0) <= r_sra;
				output(63 downto 32) <= (others => '0');
				in_ready(9 downto 0) <= (others => '0');
				in_ready(10) <= input_ready;
				in_ready(17 downto 11) <= (others => '0');	

			when OPCODE_ROR => output(31 downto 0) <= r_ror;
				output(63 downto 32) <= (others => '0');
				in_ready(10 downto 0) <= (others => '0');
				in_ready(11) <= input_ready;
				in_ready(17 downto 12) <= (others => '0');	
							


			when OPCODE_ROL => output(31 downto 0) <= r_rol;
				output(63 downto 32) <= (others => '0');
				in_ready(11 downto 0) <= (others => '0');
				in_ready(12) <= input_ready;
				in_ready(17 downto 13) <= (others => '0');		

							
						
			when OPCODE_FADD => output(31 downto 0) <= r_fadd;
				output(63 downto 32) <= (others => '0');
				in_ready(12 downto 0) <= (others => '0');
				in_ready(13) <= input_ready;
				in_ready(17 downto 14) <= (others => '0');
						
			when OPCODE_FSUB => output(31 downto 0) <= r_fsub;
				output(63 downto 32) <= (others => '0');
				in_ready(13 downto 0) <= (others => '0');
				in_ready(14) <= input_ready;
				in_ready(17 downto 15) <= (others => '0');				
							

			when OPCODE_FMULT => output(31 downto 0) <= r_fmult;
				output(63 downto 32) <= (others => '0');
				in_ready(14 downto 0) <= (others => '0');
				in_ready(15) <= input_ready;
				in_ready(17 downto 16) <= (others => '0');				
							
			when OPCODE_AND => output(31 downto 0) <= r_and;	--
				output(63 downto 32) <= (others => '0');
				in_ready(15 downto 0) <= (others => '0');
				in_ready(16) <= input_ready;
				in_ready(17) <= '0';


			when others =>
				NULL;
			end case;
		end if;
	  end if;
   end process;
  Result <= output;
  --result_rdy <= result_ready;
  output_ready <=  result_ready(0) or result_ready(1)  or result_ready(2) or result_ready(3) or result_ready(4) or result_ready(5) 
  																	or 
  				   result_ready(6) or result_ready(7) or result_ready(8) or result_ready(9) or result_ready(10) or result_ready(11)
  				   													or 
  				   result_ready(12) or result_ready(13) or result_ready(14) or result_ready(15) or result_ready(16)  or result_ready(17);	
end BEHAVIORAL;