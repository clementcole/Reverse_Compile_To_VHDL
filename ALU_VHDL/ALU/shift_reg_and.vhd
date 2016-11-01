library ieee;
use ieee.std_logic_1164.all;

entity shift_reg_and is
	port(clk      : in std_logic;
		 rst      : in std_logic;
	     data_in  : in std_logic;
	     data_out : out std_logic);
end shift_reg_and;

architecture arc of shift_reg_and is
	signal reg : std_logic_vector( 0 downto 0);

begin
	process(clk) 
	begin
		if( rising_edge(clk)) then
			reg(0) <= data_in;


		elsif(rst = '1') then
			reg(0) <= '0';
		end if;
		data_out <= reg(0);
	end process;

end arc;
