library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.NUMERIC_STD.ALL;
library work;
use work.opcodes.all;


entity generic_counter is
	port( count : buffer std_logic_vector(5 downto 1);
		  clk 	: in std_logic; 
		  rst   : in std_logic);
end entity;


architecture arch of generic_counter is 
	constant rst_period : time := 5 ns; 
	constant clk_up_period : time := 10 ns;
	signal reset : std_logic;

	function counting(val : std_logic_vector) return std_logic_vector
	is
		alias arb : std_logic_vector(val'length downto 1) is val;
		variable result : std_logic_vector(arb'range) := arb;
		variable carry : std_logic := '1';

	begin 
		for i in arb'low to arb'high loop
			result(i) := (arb(i) xor carry);  --Mutual exclusion
			carry := arb(i) and carry;      --And
			exit when carry = '0';
		end loop;
		return result;
	end counting;

	begin
		COUNT_RESET:
		process(clk)
		begin
			if (rst = '1') then
				if rst'event then
					count <= (others => '0') after rst_period;
				end if;
			elsif clk'event and (clk = '1')  then
				count <= counting(count) after clk_up_period;
			end if;
		end process;
end arch;