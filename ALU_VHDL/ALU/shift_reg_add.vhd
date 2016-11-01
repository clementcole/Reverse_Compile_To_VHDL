library ieee;
use ieee.std_logic_1164.all;

entity shift_reg_add is
	port(clk      : in std_logic;
		 rst	  : in std_logic;
		 add_sub_input_ready   : in std_logic;
	     add_sub_output_ready  : out std_logic);
end shift_reg_add;

architecture arc of shift_reg_add is
	signal reg : std_logic_vector(0 downto 0);

begin
	--mult_output_ready <= reg(0);
	process(clk) is 
	begin
	if( rising_edge(clk) and rst = '0' ) then 
		reg(0) <= add_sub_input_ready;
	elsif (rst = '1') then
		reg(0) <= '0';
	end if;
	end process;
	add_sub_output_ready <= reg(0);
	
end arc;
--High frequency Trading
--http://www.mathworks.com/matlabcentral/fileexchange/31060-cointegration-and-pairs-trading-with-econometrics-toolbox
--http://www.mathworks.com/videos/cointegration-and-pairs-trading-with-econometrics-toolbox-81799.html?form_seq=conf1428&elqsid=1472675076537&potential_use=Education&country_code=US
--http://numericalmethod.com/papers/course1/lecture1.pdf
--http://www.mathworks.com/help/stateflow/examples.html#d0e19
--http://www.mathworks.com/help/matlab/examples/basic-matrix-operations.html
--https://github.com/tharbaum/FIFO_Seboui/tree/master/12_FIFO/1140/double_FIFO/double_FIFO.data/constrs_2
--https://www.youtube.com/watch?v=UnuZyAAc5z4
--https://www.youtube.com/results?search_query=podcast+on+linguistic

--Philosophy
--http://www.counterbalance.org/enviro/hpaul-frame.html