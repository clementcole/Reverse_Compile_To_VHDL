
----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/30/2016 07:52:58 PM
-- Design Name: 
-- Module Name: opcodes - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library IEEE;
--library UNISIM;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_signed.all;
use IEEE.NUMERIC_STD.ALL;
--use UNISIM.VComponents.all;

package opcodes is
--variable width : integer := 16;
--variable N_bits : integer;
--type dynamicmem is array(natural range <>) of std_logic_vector(width-1 downto 0);
--type staticmem is array(0 to width-1) of std_logic_vector(width-1 downto 0);
function twocomplement(data : std_logic_vector) return std_logic_vector;
function to_std_logic_vector(s : string) return std_logic_vector;
function vec_to_string( s : string ) return string; 
function initialize(para : signed) return signed;
function extractSign(floatvalue : signed) return std_logic;
function extractMantissaSingle(floatvalue : signed) return std_logic_vector;
function extractExponentSingle(floatvalue : signed) return signed;
function multiplyFloatSingle(floatvalueA, floatvalueB : signed) return signed;
function divide(a : unsigned; b : unsigned) return unsigned;
procedure clk_gen(signal clk : out std_logic; constant FREQ : real; PHASE : time := 0 fs; signal run : std_logic);

--signal memblock8x8 : width8;
--signal memblock16x16 : width32;
--signal memblock32x32 : width
--Please ignore the intermediate values 
--signal memblock8x8 : width8;
--signal memblock16x16 : width32;
--signal memblock32x32 : width
--Please ignore the intermediate values 
constant OPCODE_CLEAR       :   std_logic_vector(7 downto 0)    :=  x"FF";  --CLEAR for resetting alu
constant OPCODE_IDLE		:	std_logic_vector(7 downto 0)	:=	x"FE";	--IDLE for reseting alu
constant OPCODE_ADD_SUB		:	std_logic_vector(7 downto 0)	:=	x"00";	--add/sub  = 0 TESTED
constant OPCODE_MULT		:	std_logic_vector(7 downto 0)	:=	x"01";	--MULT	  = TESTED
constant OPCODE_DIV			:	std_logic_vector(7 downto 0)	:= 	x"02";	--DIV  = NOT TESTED
constant OPCODE_OR			:	std_logic_vector(7 downto 0)	:= 	x"03";	--OR  = TESTED
constant OPCODE_NOR			: 	std_logic_vector(7 downto 0)	:=	x"04";	--NOR = TESTED
constant OPCODE_XOR			: 	std_logic_vector(7 downto 0)	:=	x"05";	--XOR  = TESTED
constant OPCODE_XNOR		: 	std_logic_vector(7 downto 0)	:=	x"06";	--XNOR = TESTED 
constant OPCODE_AND			:	std_logic_vector(7 downto 0)	:=	x"07";	--AND  = TESTED
constant OPCODE_NOT			: 	std_logic_vector(7 downto 0)	:=	x"08";	--NOT  = TESTED
constant OPCODE_SLA			: 	std_logic_vector(7 downto 0)	:=	x"09";	--SLA  = TESTED
constant OPCODE_SRA			: 	std_logic_vector(7 downto 0)	:=	x"0A";	--SRA  = TESTED
constant OPCODE_SLL			: 	std_logic_vector(7 downto 0)	:=	x"0B";	--SLL  = TESTED
constant OPCODE_SRL			: 	std_logic_vector(7 downto 0)	:=	x"0C";	--SRL = TESTED
constant OPCODE_ROR			:	std_logic_vector(7 downto 0)	:=  x"0D";	--ROR = TESTED
constant OPCODE_ROL			:	std_logic_vector(7 downto 0)	:= 	x"0E";	--ROL = TESTED
constant OPCODE_FADD		: 	std_logic_vector(7 downto 0)	:=	x"0F";	--FADD = TESTED
constant OPCODE_FSUB		: 	std_logic_vector(7 downto 0)	:=	x"10";	--FSUB = TESTED
constant OPCODE_FMULT		: 	std_logic_vector(7 downto 0)	:=	x"11";	--FMULT  = TESTED
constant OPCODE_FDIV		:   std_logic_vector(7 downto 0)    :=  x"12";	--FDIV = NOT YET		
end package;

package body opcodes is
    procedure clk_gen(signal clk : out std_logic; constant FREQ : real; PHASE : time := 0 fs; signal run : std_logic) is
	constant HIGH_TIME   : time := 0.5 sec / FREQ;  -- High time as fixed value
  	variable low_time_v  : time;                    -- Low time calculated per cycle; always >= HIGH_TIME
  	variable cycles_v    : real := 0.0;             -- Number of cycles
  	variable freq_time_v : time := 0 fs;            -- Time used for generation of cycles
	begin
  	-- Check the arguments
  	assert (HIGH_TIME /= 0 fs) report "clk_gen: High time is zero; time resolution to large for frequency" severity FAILURE;
  	-- Initial phase shift
  	clk <= '0';
  	--wait for PHASE;
  	-- Generate cycles
  	loop
    		-- Only high pulse if run is '1' or 'H'
   		 if (run = '1') or (run = 'H') then
      		clk <= run;
    	end if;
    	--wait for HIGH_TIME;
    	-- Low part of cycle
   	 clk <= '0';
    	low_time_v := 1 sec * ((cycles_v + 1.0) / FREQ) - freq_time_v - HIGH_TIME;  -- + 1.0 for cycle after current
    	--wait for low_time_v;
    	-- Cycle counter and time passed update
    	cycles_v := cycles_v + 1.0;
   	 freq_time_v := freq_time_v + HIGH_TIME + low_time_v;
 	 end loop;
	end procedure;


    function twocomplement(data : std_logic_vector) 
        return std_logic_vector is
        variable temp : std_logic_vector(data'length downto 0);
    begin
		temp := std_logic_vector( to_unsigned(to_integer(unsigned(not(data))) + 1, data'length));
      return temp;
    end twocomplement;

    function to_std_logic_vector(s : string) 
	return std_logic_vector is
		variable r : std_logic_vector(s'length * 8 downto 0);
	begin
		for i in 1 to s'high loop
			r(i * 8 - 1 downto (i - 1) * 8) := std_logic_vector( to_unsigned( character'pos(s(i)) , 8 ) ) ;
		end loop ;
	return r ;
    end to_std_logic_vector;

    function vec_to_string( s : string )
	return string 
	is
		variable r : string(s'high downto s'low) ;
	begin
		for i in 1 to s'high loop
			r(s'high + 1 - i) := s(i) ;
		end loop ;
	return r ;
    end vec_to_string ;

    function initialize(para : signed) 
	return signed
	is
		variable tempfunc : signed(63 downto 0);
	begin
		tempfunc := "0000000000000000000000000000000000000000000000000000000000000000";
	return tempfunc;
    end initialize;

	function divide(a : unsigned; b : unsigned) 
		return unsigned is
		variable a1 : unsigned(a'length-1 downto 0):=a;
		variable b1 : unsigned(b'length-1 downto 0):=b;
		variable p1 : unsigned(b'length downto 0):= (others => '0');
		variable i : integer:=0;
    		begin
			for i in 0 to b'length-1 loop
				p1(b'length-1 downto 1) := p1(b'length-2 downto 0);
				p1(0) := a1(a'length-1);
				a1(a'length-1 downto 1) := a1(a'length-2 downto 0);
				p1 := p1-b1;
			if(p1(b'length-1) ='1') then
				a1(0) :='0';
				p1 := p1+b1;
			else
				a1(0) :='1';
			end if;
		end loop;
		return a1;
   	end divide;
	function extractSign(floatvalue : signed) 
		return std_logic is
		variable signvalue : integer;
		variable signbit : std_logic;
		begin 
			signbit := floatvalue(floatvalue'length);
			return signbit;
	end extractSign;

	function extractMantissaSingle(floatvalue : signed) 
		return std_logic_vector is
		variable mantissa : std_logic_vector(floatvalue'length - 1 downto 0);
		begin 
			mantissa := std_logic_vector(floatvalue(22 downto 0));
			return mantissa;
	end extractMantissaSingle;

	function extractExponentSingle(floatvalue : signed) 
		return signed is
		variable exponent : std_logic_vector(7 downto 0);
		begin 
			exponent := (std_logic_vector(floatvalue(30 downto 23)));
			return signed(exponent);
	end extractExponentSingle;

	function multiplyFloatSingle(floatvalueA, floatvalueB : signed)
		return signed is
		variable product : std_logic_vector(31 downto 0);	
		begin
			product(31) 	     := extractSign(floatvalueA) xor extractSign(floatvalueB);
			product(30 downto 23) := std_logic_vector( to_signed(to_integer(extractExponentSingle(floatvalueA)) + to_integer(extractExponentSingle(floatvalueB)) , 8 ));
			product(22 downto 0) := std_logic_vector(to_signed(to_integer( unsigned(extractMantissaSingle(floatvalueA))) * to_integer(unsigned(extractMantissaSingle(floatvalueB))) , 23));
			return signed(product); 
	end multiplyFloatSingle;
			
end opcodes;


