library ieee;
library work;
use ieee.std_logic_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.ALL;
use IEEE.STD_LOGIC_TEXTIO.all;
use STD.TEXTIO.all;
use work.opcodes.all;
use work.Components.all;


entity fft_dfg is
		generic(data_width  : 	integer := 32);
		port(	
			clk     			: in std_logic;
			rst     			: in std_logic;
			in_rdy				: in std_logic;
			w 					: in std_logic;
			ar1                 : in std_logic;
			ai1                 : in std_logic;
			



			out_rdy             : out std_logic;);
end fft_dfg;

architecture arch of fft_dfg is


end fft_dfg;