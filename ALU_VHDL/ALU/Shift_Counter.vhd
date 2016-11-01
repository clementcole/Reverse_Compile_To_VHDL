library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


entity Shift_Counter is
	port( clk : in std_logic;
	      rst : in std_logic;
	      f_count_out  : out std_logic_vector( 3 downto 0);
	      b_count_out  : out std_logic_vector(3 downto 0);
	      fr_count_out : out std_logic_vector(3 downto 0)
	    
	);
end entity;


architecture behavioral of Shift_Counter is
constant count_stop  : std_logic_vector(3 downto 0) := X"C";
signal counter_b : std_logic_vector(4 downto 0);
signal counter_f : std_logic_vector(3 downto 0);
signal counter_fr : std_logic_vector(3 downto 0);

begin
--
--Starting counter process
--
process(rst, clk, counter_f, counter_b)
begin
	if(rising_edge(clk)) then
		--initialize counters on reset
		if(rst = '1') then
			counter_f <= (others => '0');
			counter_b <= (others => '0');
			counter_fr <= (others => '0');
		else
			counter_f <= std_logic_vector(unsigned(counter_f) + 1);

			--forward counter
			if(counter_f /= count_stop) then
				counter_f <= std_logic_vector(unsigned(counter_f) + 1);
			end if;

			--backward counter
			if(counter_b(4) = '0') then
				counter_b <= std_logic_vector(unsigned(counter_b) - 1);
			end if;
		end if;
	end if;
end process;

-------------------------------------------------
--Process for outputs
-------------------------------------------------
process(rst, clk)
begin
	if(rising_edge(clk)) then
		if(rst = '1') then
			f_count_out <= (others => '0');
			b_count_out <= (others => '0');
			fr_count_out <= (others => '0');

		else
			f_count_out <= counter_f;
			b_count_out <= counter_b(3 downto 0);
			fr_count_out <= counter_fr;
		end if;
	end if;
end process;
end behavioral; 
