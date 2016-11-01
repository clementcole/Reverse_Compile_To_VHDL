library ieee;
use ieee.std_logic_1164.all;

entity shift_reg_mult is
	port(clk      			: in std_logic;
		 rst				: in std_logic;
	     mult_input_ready  	: in std_logic;
	     mult_output_ready 	: out std_logic);
end shift_reg_mult;

architecture arc of shift_reg_mult is
	signal reg : std_logic_vector(5 downto 0) := (others => '0');

begin
	--mult_output_ready <= reg(0);
	process(clk) is 
	begin
	if( rising_edge(clk) and rst = '0') then
			reg(5) <= mult_input_ready;
			reg(4) <= reg(5);
			reg(3) <= reg(4);
			reg(2) <= reg(3);
			reg(1) <= reg(2);
			reg(0) <= reg(1);
    	--else
    elsif(rst = '1') then 
    		reg(5) <= '0';
			reg(4) <= '0';
			reg(3) <= '0';
			reg(2) <= '0';
			reg(1) <= '0';
			reg(0) <= '0';
		--end if;
	end if;
	end process;
	mult_output_ready <= reg(0);
end arc;
