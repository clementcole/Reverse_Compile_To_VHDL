library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;
use work.Components.all;


entity Difference_Of_Products is
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
			in_rdy_sum 			: buffer std_logic;
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
end Difference_Of_Products;

architecture arch of Difference_Of_Products is
	--Equation is E = MC^2


		signal input_mult1_ready  : std_logic := '0'; 
		signal input_mult2_ready  : std_logic := '0'; 
		signal input_sum_ready 	  : std_logic := '0'; 
		signal output_sum_ready   : std_logic := '0';
		signal output_mult1_ready : std_logic := '0';
		signal output_mult2_sready : std_logic := '0';
		
begin

	in_rdy_mult1 <= in_rdy; 
	in_rdy_mult2 <= in_rdy; 

	in_rdy_sum <= out_rdy_mult2 and out_rdy_mult1;
	out_rdy <=  out_rdy_sum;



	--x*y
	X_TIMES_Y: entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
			A 				=>      x,
			B				=> 		y,
			clk				=>      clk,
			rst     		=>     	rst, 
			input_ready		=>		in_rdy_mult1,
			output_ready	=>		out_rdy_mult1,
			Operation		=>      MULT1,
			Result 			=>   	PRODUCT_x_y
	);
	--
	--reg_shift_mult here
	--
	--a*b
	A_TIMES_B : entity work.ALU_EXPERIMENT_32
	generic map(data_width => data_width)
	port map(
			A 				=>      a,
			B				=> 		b,
			clk				=>      clk,
			rst   			=>     	rst, 
			input_ready		=>		in_rdy_mult2,
			output_ready	=>      out_rdy_mult2,
			Operation		=>      MULT2,
			Result 			=>   	PRODUCT_a_b
	);
	--
	--reg_shift_mult here
	--

	--(x*y)+(a*b)
	XY_MINUS_AB : entity work.ALU_EXPERIMENT_32 
	generic map (data_width => data_width)
	port map( 
			A 				=>   PRODUCT_x_y(31 downto 0), 
			B  				=>   PRODUCT_a_b(31 downto 0), 
			clk 			=>   clk, 
			rst  			=>   rst, 
			input_ready 	=>   in_rdy_sum,
			output_ready 	=>   out_rdy_sum, 
			Operation       =>   SUM, 
			Result 			=>   Result );
	--
	--reg_shift_add here
	--
	
end arch;

