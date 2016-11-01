library ieee;
use ieee.std_logic_1164.all;

entity shift_reg_xnor is
	port(clk      : in std_logic;
		 rst 	  : in std_logic;
	     data_in  : in std_logic;
	     data_out : out std_logic);
end shift_reg_xnor;

architecture arc of shift_reg_xnor is
	signal reg : std_logic_vector( 0 downto 0);

begin
	process(clk) 
	begin
		if(rising_edge(clk)) then
				--reg(2) <= data_in;
				--reg(1) <= reg(2);
				reg(0) <= data_in;
		elsif(rst = '1') then
			
			--reg(2) <= '0';
			--reg(1) <= '0';
			reg(0) <= '0';
			
		end if;
	end process;
		data_out <= reg(0);
end arc;
