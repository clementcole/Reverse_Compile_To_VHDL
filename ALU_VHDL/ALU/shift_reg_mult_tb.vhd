library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;



entity shift_reg_mult_tb is
end;

architecture testbench of shift_reg_mult_tb is
	----------------------------------------------
	-- shift Register component
	----------------------------------------------
	component shift_reg_mult is  
		port(clk      	: in std_logic;
		 rst				: in std_logic;
	     mult_input_ready  	: in std_logic;
	     mult_output_ready 	: out std_logic);
	end component;

	signal clk	: std_logic := '0';
	signal rst, mult_input_ready, mult_output_ready : std_logic;

	begin
		uut : shift_reg_mult 
			port map( clk => clk, rst => rst, mult_input_ready => mult_input_ready, mult_output_ready => mult_output_ready);

	clock_gen : process is
	begin
	    wait for 5 ns;	clk <= not (clk ); 
	end process;

	unit_test : process
	begin
   		wait for 5 ns; rst  <= '1';
   		wait for 5 ns; rst  <= '0';
   		mult_input_ready <= '1';
   		wait for 60 ns;
   		wait for 5 ns; rst <= '1';
   		wait for 5 ns; rst <= '0';
   		mult_input_ready <= '0';
   		wait for 60 ns;
   		wait for 5 ns; rst <= '1';
   		wait for 5 ns; rst <= '0';
   		mult_input_ready <= '1';
   		wait;
	end process;



end testbench;
