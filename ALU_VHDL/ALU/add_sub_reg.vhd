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


entity add_sub_reg is
	generic(bits : integer := 32);
	port (
		A     : in signed(31 downto 0);
		B     : in signed(31 downto 0);
		clk   : in std_logic; 
		rst   : in std_logic; 
		input_ready : in std_logic; 
		output_ready : out std_logic; 
		Result : out std_logic_vector(32 downto 0)
		);
end;

architecture behavioral of add_sub_reg is 

	component add_sub_n is 
	generic ( bits   : integer :=  bits);
	port ( 
			clk  : in std_logic; 
			A    : in signed(31 downto 0);
			B    : in signed(31 downto 0);
			result : out std_logic_vector(32 downto 0));
	end component;

	component shift_reg_add is 
		port(clk      : in std_logic;
		 rst	  : in std_logic;
		 add_sub_input_ready   : in std_logic;
	     add_sub_output_ready  : out std_logic);
	end component;

	begin 
		PM_ADD_SUB_READY_SIGNAL : shift_reg_add
			port map( clk => clk, rst => rst, add_sub_input_ready => input_ready, add_sub_output_ready => output_ready);
		--output_ready <= input_ready;
		PM_ADD_SUB  : add_sub_n 
			port map(clk => clk, A => A, B => B, result => Result);

end architecture;  
