----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/30/2016 07:52:58 PM
-- Design Name: 
-- Module Name: opcodes - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
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
library IEEE;
--library UNISIM;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_signed.all;
use IEEE.NUMERIC_STD.ALL;
use work.opcodes.all;

package Components is

   component AlU_EXPERIMENT_32 is
	generic(data_width 	:	 	integer := 32);
	port(   
		A 		:		in std_logic_vector(31 downto 0); --input operands
		B		: 		in std_logic_vector(31 downto 0);
		clk		:               in std_logic;
		reset		:		in std_logic;
		go		:		in std_logic;
		done		:		in std_logic;
		Operation	: 		in std_logic_vector(7 downto 0); --select operation
		Result 		: 		out std_logic_vector(63 downto 0));  --Reg3
    end component;


	---------------------------------------------------------------------------
	-- Components adder 32 bit, subtractor 32, floating point arithmetic singledata_width
	---------------------------------------------------------------------------data_width
	component add_sub_n is
		generic ( bits 	: integer);
		port (	A	: in signed(31 downto 0);
			B	: in signed(31 downto 0);
			Result 	: out signed(32 downto 0));
	end component;
	
	component mult is
	PORT (
    			clk : IN STD_LOGIC;
    			 a : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
   			 b : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
   			 p : OUT STD_LOGIC_VECTOR(63 DOWNTO 0)
	      );
	end component;
	
	
	
	component fp_mult is
		port(  
			a 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			b 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			clk 	: IN STD_LOGIC;
			result : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;

	

	component fp_add
		port(	a 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			b 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			clk 	: IN STD_LOGIC;
			result 	: OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;
	
	
	
	component fp_sub
		port( 	a 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			b 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
			clk	: IN STD_LOGIC;
			result 	: OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;
	
end package Components;

package body Components is
end Components;


