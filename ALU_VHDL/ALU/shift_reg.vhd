library ieee;
use ieee.std_logic_1164.all;

entity shift_reg is
	port(clk      			: in std_logic;
		input_ready			: in std_logic;
	     parallel_load  	: in std_logic_vector(10 downto 0);
	     output_ready 		: out std_logic);
end shift_reg;

architecture arc of shift_reg is
	signal temp_reg : std_logic_vector( 10 downto 0);
	signal temp_Out : std_logic;

begin
	
	process(clk) 
	--variable temp_reg : std_logic_vector(10 downto 0);
	begin 
		if (rising_edge(clk) and input_ready = '1') then
				temp_reg(10) <= parallel_load(9);
				temp_reg(9) <= parallel_load(8);
				temp_reg(8) <= parallel_load(7);
				temp_reg(7) <= parallel_load(6);
				temp_reg(6) <= parallel_load(5);
				temp_reg(5) <= parallel_load(4);
				temp_reg(4) <= parallel_load(3);
				temp_reg(3) <= parallel_load(2);
				temp_reg(2) <= parallel_load(1);
				temp_reg(1) <= parallel_load(0);
				temp_reg(0) <= '0';
		elsif(input_ready = '0') then
				temp_reg(10) <= '0';
				temp_reg(9) <= '0';
				temp_reg(8) <= '0';
				temp_reg(7) <= '0';
				temp_reg(6) <= '0';
				temp_reg(5) <= '0';
				temp_reg(4) <= '0';
				temp_reg(3) <= '0';
				temp_reg(2) <='0';
				temp_reg(1) <= '0';
				temp_reg(0) <= '0';
		end if;
		output_ready <= temp_reg(10);
	end process;
end arc;

--if(input_ready = '1') then
		--	temp_reg (10 downto 0) <= parallel_load(10 downto 0);
--temp_Out <= temp_reg(10);
			--temp_reg(9) <= temp_reg(8);
			--temp_reg(8) <= temp_reg(7);
			--temp_reg(7) <= temp_reg(6);
			--temp_reg(6) <= temp_reg(5);
			--temp_reg(5) <= temp_reg(4);
			--temp_reg(4) <= temp_reg(3);
			--temp_reg(3) <= temp_reg(2);
			--temp_reg(2) <= temp_reg(1);
			--temp_reg(1) <= temp_reg(0);
			--temp_reg(0) <= '0';
			--temp_reg(10 downto 1) <= temp_reg(9 downto 0);
			--temp_reg(0) <= '0';