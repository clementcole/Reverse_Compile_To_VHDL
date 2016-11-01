library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;


entity fifo_32_tb is
end fifo_32_tb;


architecture behaviorial of fifo_32_tb is 

component fifo_32 
 PORT (
    clk : IN STD_LOGIC;
    rst : IN STD_LOGIC;
    din : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    wr_en : IN STD_LOGIC;
    rd_en : IN STD_LOGIC;
    dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    full : OUT STD_LOGIC;
    empty : OUT STD_LOGIC
  );
end component;

--inputs 
signal rst : std_logic;
signal clk : std_logic;
signal din : std_logic_vector(31 downto 0) := (others  => '0');
signal wr_en : std_logic := '0';
signal rd_en : std_logic := '0';

--output signals
signal full : std_logic := '0';
signal dout : std_logic_vector(31 downto 0);-- := (others  => '0');
signal empty : std_logic;
signal period : time := 10 ns;


begin
	uut : fifo_32 
	port map(clk => clk,  rst => rst, din => din, wr_en => wr_en, rd_en => rd_en, dout => dout, full => full, empty => empty );


	-- Clock process definitions
  clk_process :process
  begin
  		clk <= '1';
  		wait for (period/2);
  		clk <= '0';
  		wait for (period/2);
  end process;
 
 

 uut_proc : process
 begin
    wr_en <= '0';
    rd_en <= '0';
    din <= x"00000000";
    rst <= '1';
    wait for (period);
    rst <= '0';
    wait for (5 * period);
    din <= x"00000001";
    wr_en <= '1';
    wait for period;
    din <= x"00000002";
    wait for period;
    din <= x"00000003";
    wait for period;
    din <= x"00000004";
    wait for period;
    din <= x"00000005";
    wait for period;
    din <= x"00000006";
    wait for period; 
    din <= x"00000007";
    wait for period;
    din <= x"00000008";
    wait for period;
    din <= x"00000009";
    wait for period;
    din <= x"0000000A";
    wait for period;
    din <= x"0000000B";
    wait for period;
    din <= x"0000000C";
    wait for period;
    din <= x"0000000D";
    wait for period;
    din <= x"0000000E";
    wait for period;
    din <= x"0000000F";
    wait for period;
    din <= x"00000010";
    wait for period;
    din <= x"00000000";
    wait for period;
    wr_en <= '0';
    rd_en <= '1';
    wait for (17 * period);
    wr_en <= '0';
    rd_en <= '0';
    rst <= '1';
    wait for period;
    rst <= '0';
    wait for (5 * period);

    din <= x"00000010";
    wr_en <= '1';
    wait for period;
    din <= x"00000011";
    wait for period;
    din <= x"00000012";
    wait for period;
    din <= x"00000014";
    wait for period;
    din <= x"00000015";
    wait for period;
    din <= x"00000016";
    wait for period; 
    din <= x"00000017";
    wait for period;
    din <= x"00000018";
    wait for period;
    din <= x"00000019";
    wait for period;
    din <= x"0000001A";
    wait for period;
    din <= x"0000001B";
    wait for period;
    din <= x"0000001C";
    wait for period;
    din <= x"0000001D";
    wait for period;
    din <= x"0000001E";
    wait for period;
    din <= x"0000001F";
    wait for period;
    din <= x"00000020";
    wait for period;
    din <= x"00000000";
    wait for period;
    wr_en <= '0';
    rd_en <= '1';
    wait for (17 * period);
    wr_en <= '0';
    rd_en <= '0';
    rst <= '1';
    wait for period;
    rst <= '0';
    wait for (5 * period);
    wait;
    
  end process;
end behaviorial;
--Notes 
--Fifo takes 14 clock cycles to complete reading all the data for 16 32bit hex values. 
--nrst_t <= '0' , '1' after 15 ns;
--  clk_t <= not clk_t after 2 ns;
--  readReq_t <= '1' after 21 ns , '0' after 23 ns, '1' after 41 ns, '0' after 45 ns , '1' after 53 ns;
--  writeReq_t <= '1' after 28 ns, '0' after 31 ns , '1' after 33 ns , '0' after 35 ns, '1' after 37 ns, '1' after 45 ns, '0' after 47 ns , '1' after 49 ns, '0' after 51 ns;
--  data_in_t <= "11111111" after 29 ns, "11111110" after 33 ns , "11111100" after 37 ns, "11111000" after 45 ns, "11110000" after 49 ns;
