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


entity demux_1_to_2 is 
	port ( 	Previous_Level_ALU_Output 		: in std_logic_vector(31 downto 0); -- Includes the out_ready signal to avoid using two demuxes
			Previous_Level_Output_Ready 	: in std_logic;
			clk		   						: in std_logic;  -- Sync with above ALU
			rst        						: in std_logic;  -- Sync reset with above ALU
			Select_Lines					: in std_logic;
			Next_Level_ALU_Input_1_0		: out std_logic_vector(31 downto 0);
			Next_Level_ALU_Input_1_1        : out std_logic_vector(31 downto 0);
			Next_Level_Input_Ready_1_0		: out std_logic;
			Next_Level_Input_Ready_1_1		: out std_logic);
end demux_1_to_2;

architecture behavioral of demux_1_to_2 is
begin
	process(Previous_Level_ALU_Output, Previous_Level_Output_Ready) is 
	begin
		if (Select_Lines = '0') then
			Next_Level_ALU_Input_1_0 	<= Previous_Level_ALU_Output;
			Next_Level_Input_Ready_1_0 	<= Previous_Level_Output_Ready;

		elsif(Select_Lines = '1') then 
			Next_Level_ALU_Input_1_1 	<= Previous_Level_ALU_Output;
			Next_Level_Input_Ready_1_1 	<= Previous_Level_Output_Ready;			

		else 
			null;
		end if;
	end process;

end behavioral;