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


entity demux_1_to_2_tb is
end demux_1_to_2_tb;


architecture testbench of demux_1_to_2_tb is
	signal previous_level_alu_output, next_level_alu_1_0, next_level_alu_1_1 : std_logic_vector(31 downto 0);
	signal clock, reset, select_Lines, previous_level_output_ready, next_level_input_ready_1_0, next_level_input_ready_1_1 : std_logic;

	begin
		uut: entity work.demux_1_to_2 
			port map ( 	Previous_Level_ALU_Output 		=> previous_level_alu_output, 
						Previous_Level_Output_Ready 	=> previous_level_output_ready,
						clk		   						=> clock,
						rst        						=> reset,
						Select_Lines					=> select_lines,
						Next_Level_ALU_Input_1_0		=> next_level_alu_1_0,
						Next_Level_ALU_Input_1_1        => next_level_alu_1_1,
						Next_Level_Input_Ready_1_0		=> next_level_input_ready_1_0,
						Next_Level_Input_Ready_1_1		=> next_level_input_ready_1_1 );
	--------------------------------------------------------------
	-- Clock gen
	--------------------------------------------------------------
	clock_gen : process is
	begin
		wait for 5 ns;
		clock <= '1'; 
		wait for 5 ns;
		clock <= '0'; 
	end process;


	--------------------------------------------------------------
	-- Unit test
	--------------------------------------------------------------
	test_proc: process 
	begin
		wait for 10 ns;
		previous_level_output_ready <= '0';
		previous_level_alu_output <= x"FFFFFFFD";
		reset <= '0';
		select_lines <= 'X';
		
		wait for 20 ns;
		previous_level_output_ready <= '1';
		previous_level_alu_output <= x"00000004";
		select_lines <= '0';
		
		wait for 30 ns;
		previous_level_output_ready <= '1';
		previous_level_alu_output <= x"00000010";
		select_lines <= '1';
		
		wait for 40 ns;
		previous_level_output_ready <= '1';
		previous_level_alu_output <= x"00000012";
		select_lines <= '0';
			
		wait for 50 ns;
		previous_level_output_ready <= '1';
		previous_level_alu_output <= x"00000013";
		select_lines <= '1';
		
		wait;	

	end process;
end testbench;