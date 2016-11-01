library ieee;
use ieee.std_logic_1164.all;

entity shift_reg_fmult is
	port(clk      			: in std_logic;
		 rst				: in std_logic;
	     data_in  	: in std_logic;
	     data_out 	: out std_logic);
end shift_reg_fmult;

architecture arc of shift_reg_fmult is
	signal reg : std_logic_vector(4 downto 0) := (others => '0');

begin
	
	process(clk) is 
	begin
	if( rising_edge(clk)) then
			reg(4) <= data_in;
			reg(3) <= reg(4);
			reg(2) <= reg(3);
			reg(1) <= reg(2);
			reg(0) <= reg(1);
    elsif(rst = '1') then 
			reg(4) <= '0';
			reg(3) <= '0';
			reg(2) <= '0';
			reg(1) <= '0';
			reg(0) <= '0';
	end if;
	end process;
	data_out <= reg(0);
end arc;
