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


entity alu_fifo is
	port(   
		A 				:		in std_logic_vector(31 downto 0); --input operands
		B				: 		in std_logic_vector(31 downto 0);
		clk				:       in std_logic;
		rst 			:       in std_logic;
		nd_rdy			:		in std_logic; 
		out_rdy			:		out std_logic;
		Op 				: 		in std_logic_vector(7 downto 0); --select operation
		Result 			: 		out std_logic_vector(63 downto 0));
end;

architecture BEHAVIORAL of ALU_FIFO is
	--input_signals;
	signal clock, reset, in_ready, out_ready : std_logic;
	signal operation   : std_logic_vector(7 downto 0);
	signal Result      : std_logic_vector(63 downto 0);
	signal A, B        : std_logic_vector(63 downto 0);
	begin


end BEHAVIORAL; 

--component fifo_32 
-- PORT (
--    clk : IN STD_LOGIC;
--    rst : IN STD_LOGIC;
--    din : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
--    wr_en : IN STD_LOGIC;
--    rd_en : IN STD_LOGIC;
--    dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
--    full : OUT STD_LOGIC;
--    empty : OUT STD_LOGIC
--  );
--end component;

--1. Initialiaze all in signals to '0'
--   wr_en <= '0';
--   rd_en <= '0';
--   din <= x"00000000";
--
--2. Reset the FIFO Unit for 1 clock cycle
--   rst <= '1'; wait for Period;
--	 set rst back to '0'
--   load data into din
--   din <= '00000000';