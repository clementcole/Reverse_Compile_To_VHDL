library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;
use work.Components.all;


entity mult_add_unbalanced_eq is
		generic(data_width  : 	integer := 32);
		port(	
			clk     			: in std_logic;
			rst     			: in std_logic;
			in_rdy				: in std_logic;
			in_rdy_mult 	    : out std_logic;
			out_rdy_mult 	  	: out std_logic;
			in_rdy_sum 			: out std_logic;
			out_rdy_sum         : out std_logic;
			in_rdy_final 		: out std_logic;
			out_rdy_final       : out std_logic;
			x	   	        	: in std_logic_vector(31 downto 0);
			y	    	    	: in std_logic_vector(31 downto 0);
			a 					: in std_logic_vector(31 downto 0);
			b 					: in std_logic_vector(31 downto 0);
			opcode1         	: in std_logic_vector(7 downto 0);
			opcode2 			: in std_logic_vector(7 downto 0);
			opcode3		    	: in std_logic_vector(7 downto 0);
			X_TIMES_Y       	: out std_logic_vector(63 downto 0);
			A_PLUS_B 			: out std_logic_vector(63 downto 0);
			X_TIMES_Y_PLUS_A_PLUS_B           : out std_logic_vector(63 downto 0));
			--Result	    		: out std_logic_vector(63 downto 0));
end mult_add_unbalanced_eq;

architecture arch of mult_add_unbalanced_eq is
	signal inputA_product_x_y, inputB_product_x_y, inputA_sum_a_b, inputB_sum_a_b : std_logic_vector(31 downto 0); --inputs x, y, a, b, {32 bits each}
	signal clk_product_x_y, rst_product_x_y,  clk_sum_a_b, rst_sum_a_b, clk_final_sum, rst_final_sum : std_logic;  --inputs clk1, clk2, rst1, rst2, {1 bit each}
	signal in_rdy_product_x_y, in_rdy_sum_a_b, in_rdy_final_sum : std_logic;									   --ready signals rdy1, rd2, rd3, {1 bit each}
	signal out_rdy_product_x_y, out_rdy_sum_a_b, out_rdy_final_sum : std_logic;									   --output ready signals (xy), (a+b) and (xy) + (a + b) {1 bit each} 
	signal op_product_x_y, op_sum_a_b, op_final_sum : std_logic_vector(7 downto 0);							   --opcodes {plus, mult and plus}
	signal result_product_x_y, result_sum_a_b, result_final_sum : std_logic_vector(63 downto 0);               --result signals {64 bits each}		

	begin 

		clk_product_x_y <= clk;
		clk_sum_a_b <= clk;
		clk_final_sum <= clk;

		rst_product_x_y <= rst;
		rst_sum_a_b <= rst;
		rst_final_sum <= rst;

		in_rdy_product_x_y <= in_rdy;
		in_rdy_sum_a_b <= in_rdy;
		in_rdy_final_sum <= (out_rdy_product_x_y and out_rdy_sum_a_b);

		in_rdy_sum <= in_rdy_sum_a_b;
		in_rdy_mult <= in_rdy_product_x_y;
		in_rdy_final <= in_rdy_final_sum; 

		out_rdy_mult <= out_rdy_product_x_y;
		out_rdy_sum <= out_rdy_sum_a_b;
		out_rdy_final <= out_rdy_final_sum;
		out_rdy_final <= out_rdy_final_sum;

		op_product_x_y <= opcode1;
		op_sum_a_b <= opcode2;
		op_final_sum <= opcode3;

		inputA_product_x_y <= x;
		inputB_product_x_y <= y;
		inputA_sum_a_b <= a;
		inputB_sum_a_b <= b;

		X_TIMES_Y <= result_product_x_y;
		A_PLUS_B <= result_sum_a_b;
		X_TIMES_Y_PLUS_A_PLUS_B <= result_final_sum;

		X_MULT_Y : entity work.ALU_EXPERIMENT_32
		generic map(data_width => data_width)
		port map(
				A 				=>      inputA_product_x_y,
				B				=> 		inputB_product_x_y,
				clk				=>      clk_product_x_y,
				rst   			=>     	rst_product_x_y, 
				input_ready		=>		in_rdy_product_x_y,
				output_ready	=>      out_rdy_product_x_y,
				Operation		=>      op_product_x_y,
				Result 			=>  	result_product_x_y
		);

		A_ADD_B : entity work.ALU_EXPERIMENT_32 
		generic map(data_width => data_width)
		port map(
				A                =>     inputA_sum_a_b,
				B 				 =>     inputB_sum_a_b,
				clk 			 =>     clk_sum_a_b,
				rst              =>     rst_sum_a_b, 
				input_ready      =>     in_rdy_sum_a_b,
				output_ready     =>     out_rdy_sum_a_b,
				Operation        =>     op_sum_a_b,
				Result           =>     result_sum_a_b
		);


		FINAL_SUM : entity work.ALU_EXPERIMENT_32 
		generic map(data_width => data_width)
		port map(
				A                =>     result_product_x_y(31 downto 0),
				B 				 =>     result_sum_a_b(31 downto 0),
				clk 			 =>     clk_final_sum,
				rst              =>     rst_final_sum, 
				input_ready      =>     in_rdy_final_sum,
				output_ready     =>     out_rdy_final_sum,
				Operation        =>     op_final_sum,
				Result           =>     result_final_sum
		);
end;
