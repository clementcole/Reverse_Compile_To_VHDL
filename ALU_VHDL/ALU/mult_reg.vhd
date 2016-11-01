
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



entity mult_reg is
	generic(bits 	:	 	integer := 32);
	port( 
		A 				:		in std_logic_vector(31 downto 0); --input operands
		B				: 		in std_logic_vector(31 downto 0);
		clk   			: 		in std_logic; 
		rst   			:		in std_logic; 
		input_ready		:		in std_logic; 
		output_ready	:		out std_logic;
		Result 			: 		out std_logic_vector(63 downto 0));
end;


architecture BEHAVIORAL of mult_reg is

	component mult is
	PORT (
    		clk : IN STD_LOGIC;
    		 a : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
   			 b : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
   			 p : OUT STD_LOGIC_VECTOR(63 DOWNTO 0)
	      );
	end component;


	component shift_reg_mult is
	port(clk      			: in std_logic;
		 rst				: in std_logic;
	     mult_input_ready  	: in std_logic;
	     mult_output_ready 	: out std_logic);
	end component;

    begin 
    
    	PM_MULT_OUTPUT_READY_SIGNAL : shift_reg_mult
			port map(clk => clk, rst => rst,  mult_input_ready => input_ready, mult_output_ready => output_ready );
   
        PM_MULT : mult
			port map( clk => clk, a => A, b => B,  p => Result);


end architecture;