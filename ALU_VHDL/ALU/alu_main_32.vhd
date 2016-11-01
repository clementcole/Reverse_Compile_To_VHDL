library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;
use IEEE.NUMERIC_STD.ALL;
library work;
use work.opcodes.all;
--use work.floatpoint.all;

entity AlU_MAIN_32 is
	generic(data_width 	:	 	integer := 32);
	port(   	clk 					: 		in std_logic; -- Clock
					reset				: 		in std_logic;
					A 					:		in std_logic_vector(31 downto 0); --input operands
					B						: 		in std_logic_vector(31 downto 0);
					Operation		: 		in std_logic_vector(7 downto 0); --select operation
					Result 			: 		out std_logic_vector(63 downto 0));  --Reg3
end ALU_MAIN_32;

architecture BEHAVIORAL of ALU_MAIN_32 is
--------------------------------------
--Signals inputs/outputs temporary
---------------------------------------
signal inputA, inputB 								: std_logic_vector(data_width-1 downto 0);
signal invertB 												: std_logic_vector(31 downto 0);
signal output 												: std_logic_vector(63 downto 0);
--signal add_sub_En : std_logic;
signal op														: std_logic_vector(7 downto 0); 
signal z, n, o 												: std_logic;
signal go_fadd_sub, done_fadd_sub  		: std_logic;
signal r_add_sub, r_add, r_sub 				: signed(32 downto 0);
signal r_or, r_and, r_xor, r_xnor, r_not	: std_logic_vector(31 downto 0);
signal r_sla, r_sra, r_sll, r_srl, r_nor 		: std_logic_vector(31 downto 0);
signal r_fadd, r_fsub, r_fmult, r_fdiv 		: std_logic_vector(31 downto 0);
signal r_ror, r_rol 										: std_logic_vector(31 downto 0);
signal r_div 													: std_logic_vector(31 downto 0);
signal r_mult												: std_logic_vector(63 downto 0);
signal cin 														: std_logic;
signal cout 													: std_logic;
	---------------------------------------------------------------------------
	-- Components adder 32 bit, subtractor 32, floating point arithmetic singledata_width
	---------------------------------------------------------------------------data_width
	component add_sub_n is
		generic ( 		bits 	: integer);
		port (						A	: in signed(31 downto 0);
										B	: in signed(31 downto 0);
							Result 	: out signed(32 downto 0));
	end component;
	

	--component or_n is
	--	generic ( 		bits    : integer);
	--	port    (		clk     : in std_logic;
	--				reset	: in std_logic;
	--				inputA	: in std_logic_vector(bits-1 downto 0);
	--				inputB  : in std_logic_vector(bits-1 downto 0);
	--				r_or	: out std_logic_vector(bits-1 downto 0));
	--end component;



	--component srl_n is
	--	generic( 		bits 	: integer );
	--	port   ( 		clk	: in std_logic;
	--		 		reset	: in std_logic;
	--		 		inputA  : in std_logic_vector(bits-1 downto 0);
	--		 		inputB  : in std_logic_vector(bits-1 downto 0);
	--		 		r_srl   : out std_logic_vector(bits-1 downto 0));
	--end component;

	--component sll_n is
	--	generic(		bits 	: integer);
	--	port   (		clk	: in std_logic;
	--				reset	: in std_logic;
	--				inputA 	: in std_logic_vector(bits-1 downto 0);
	--				inputB 	: in std_logic_vector(bits-1 downto 0);
	--				r_sll  	: out std_logic_vector(bits-1 downto 0));
	--end component;
	

	
	--component sra_n is
	--	generic(		bits    : integer);
	--	port   (		clk     : in std_logic;
	--				reset	: in std_logic;
	--				inputA	: in std_logic_vector(bits-1 downto 0);
	--				inputB	: in std_logic_vector(bits-1 downto 0);
	--				r_sra	: out std_logic_vector(bits-1 downto 0));
	--end component;
	

	--component sla_n is
	--	generic(		bits    : integer);
	--	port   (		clk     : in std_logic;
	--				reset	: in std_logic;
	--				inputA	: in std_logic_vector(bits-1 downto 0);
	--				inputB	: in std_logic_vector(bits-1 downto 0);
	--				r_sla	: out std_logic_vector(bits-1 downto 0));
	--end component;
	
	

	--component and_n is
	--	generic(	bits 	: integer);
	--	port   (		clk		: in std_logic;
	--				reset			: in std_logic;
	--				inputA 		: in std_logic_vector(bits-1 downto 0);
	--				inputB 		: in std_logic_vector(bits-1 downto 0);
	--				r_and  		: out std_logic_vector(bits-1 downto 0));
	--end component;

	--component xor_n is
	--	generic (		bits 	: integer);
	--	port	(		clk	: in std_logic;
	--				reset	: in std_logic;
	--				inputA	: in std_logic_vector(bits-1 downto 0);
	--				inputB	: in std_logic_vector(bits-1 downto 0);
	--				r_xor	: out std_logic_vector(bits-1 downto 0));
	--end component;

	--component xnor_n is
	--	generic (		bits	: integer);
	--	port	(		clk	: in std_logic;
	--				reset	: in std_logic;
	--				inputA	: in std_logic_vector(bits-1 downto 0);
	--				inputB	: in std_logic_vector(bits-1 downto 0);
	--				r_xnor	: out std_logic_vector(bits-1 downto 0));
	--end component;

	--component mult is
	--	PORT (
	--				 clk 	: IN STD_LOGIC;
	--				 a 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
	--				 b 	: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
	--				 ce 	: IN STD_LOGIC;
	--				 sclr 	: IN STD_LOGIC;
	--				 p 	: OUT STD_LOGIC_VECTOR(63 DOWNTO 0));
	--end component;
	
	
	
	--component ror_n is
	--	generic(bits : integer);
	--	port (	clk 		: in std_logic;
	--				reset 	:  in std_logic;
	--				inputA : in std_logic_vector(bits-1 downto 0);
	--				inputB : in std_logic_vector(bits-1 downto 0);
	--				r_ror	 : out std_logic_vector(bits-1 downto 0));
	--end component;
	
	--component rol_n is
	--	generic (bits : integer);
	--	port ( clk : in std_logic;
	--				reset : in std_logic;
	--				inputA : in std_logic_vector(bits-1 downto 0);
	--				inputB : in std_logic_vector(bits-1 downto 0);
	--				r_rol     : out std_logic_vector(bits-1 downto 0));
	--end component;				
	
	
	--component nor_n is
	--	generic(bits 	: integer);
	--	port   (clk		: in std_logic;
	--			reset  	: in std_logic;
	--			inputA 	: in std_logic_vector(bits-1 downto 0);
	--			inputB 	: in std_logic_vector(bits-1 downto 0);
	--			r_nor   : out std_logic_vector(bits-1 downto 0));
	--end component;
	
	--component not_n is
	--	generic(bits 	: integer);
	--	port   (clk 	: in std_logic;
	--			reset 	: in std_logic;
	--			inputA 	: in std_logic_vector(bits-1 downto 0);
	--			inputB 	: in std_logic_vector(bits-1 downto 0);
	--			r_not	: out std_logic_vector(bits-1 downto 0));
	--end component;
	
	--component div_n is
	--	generic(	bits 	: integer);
	--	port   (	clk			: in std_logic;
	--					reset		: in std_logic;
	--					inputA 	: in std_logic_vector(bits-1 downto 0);	-- Numerator
	--					inputB 	: in std_logic_vector(bits-1 downto 0); -- Denomenator
	--					r_div  		: out std_logic_vector(bits-1 downto 0)); --Result
	--end component;
	
	
	component fp_mult is
		port( 	a 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				b 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				clk 	: IN STD_LOGIC;
				result : OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;

	

	component fp_add
		port(	a 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				b 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				clk 	: IN STD_LOGIC;
				result 	: OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;
	
	
	
	component fp_sub
		port( 	a 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				b 		: IN STD_LOGIC_VECTOR(31 DOWNTO 0);
				clk		: IN STD_LOGIC;
				result 	: OUT STD_LOGIC_VECTOR(31 DOWNTO 0));
	end component;
	
	


begin	
	inputA <= A;
	inputB <= B;
	
	
	
	PM_ADD_SUB : add_sub_n  
		generic map (bits => data_width)
		port map ( A => signed(inputA), B => signed(inputB), Result => (r_add_sub));

	--PM_OR	: or_n 
	--	generic map (bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_or  => r_or);

	--PM_XOR	: xor_n
	--	generic map (bits => data_width)
	--	port map    (clk => clk, reset => reset, inputA => inputA, inputB => inputB, r_xor => r_xor);

	--PM_XNOR : xnor_n
	--	generic map (bits => data_width)
	--	port map    (clk => clk, reset => reset, inputA => inputA, inputB => inputB, r_xnor => r_xnor);


	--PM_SRL : srl_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_srl  => r_srl);  
		
	--PM_SLL : sll_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_sll => r_sll);
 
	--PM_SRA : sra_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_sra => r_sra);

	--PM_SLA : sla_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_sla => r_sla);

	--PM_AND : and_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_and => r_and);
		
	--PM_DIV : div_n
	--	generic map( bits => data_width)
	--	port map(clk => clk, reset => reset, inputA => inputA, inputB => inputB, r_div => r_div);
	
	--PM_NOR : nor_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_nor=> r_nor);

	--PM_ROR : ror_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_ror => r_ror);
		
	--PM_ROL : rol_n
	--	generic map ( bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_rol => r_rol);
		
		
	--PM_NOT : not_n
	--	generic map (bits => data_width)
	--	port map    ( clk  => clk, reset => reset, inputA => inputA, inputB => inputB, r_not => r_not);
		
		
	PM_FADD : fp_add
		port map(a => inputA, b => inputB, clk => clk, result => r_fadd);

	PM_FSUB : fp_sub
		port map(a => inputA, b => inputB, clk => clk, result => r_fsub);


	PM_FMULT : fp_mult
		port map(a => inputA, b => inputB, clk => clk,  result => r_fmult);

	
	--PM_FDIV : fp_div
	--	port map(clk => clk, reset => reset, inputA => inputA, inputB => inputB, r_div => r_div);
	

			
	

	alu_control : process(clk, reset, Operation, inputA, inputB) is 
	begin 
	   if(rising_edge(clk)) then
	     if(reset = '1') then
		Result <= (others => '0');
	     else 
		case Operation is
			when OPCODE_ADD_SUB => 
				Result(32 downto 0) <= std_logic_vector(r_add_sub); 
					

			when OPCODE_OR => r_or <= inputA or inputB;	
				Result(31 downto 0) <= r_or;

			
			when OPCODE_AND => r_and <= inputA and inputB;	
				Result(31 downto 0) <= r_and;


			when OPCODE_MULT => r_mult <= std_logic_vector(signed(inputA) * signed(inputB));
				Result <= r_mult;

			when	OPCODE_DIV => r_div <= std_logic_vector(to_signed(to_integer(signed(inputA) / signed(inputB)),32));
				Result(31 downto 0) <= r_div;
				--Result(31 downto 0) <= std_logic_vector(to_signed(to_integer(signed(inputA) / signed(inputB)),32));
				
				
			when OPCODE_XOR => r_xor <= ((inputA xor inputB));
				Result(31 downto 0) <= r_xor;


			when OPCODE_XNOR => r_xnor <= ((inputA xnor inputB));
				Result(31 downto 0) <= r_xnor;
				

			when OPCODE_NOT => r_not <= not(inputA);
				Result(31 downto 0) <= r_not;

			when OPCODE_SLA => r_sla <= std_logic_vector(shift_left(signed(inputA), to_integer(unsigned(inputB))));
				Result(31 downto 0) <= r_sla;


			when OPCODE_SRA => r_sra <= std_logic_vector(shift_right(signed(inputA), to_integer(unsigned(inputB))));
				Result(31 downto 0) <= r_sra;
			
			when OPCODE_SLL => r_sll <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) sll to_integer(unsigned(inputB))) );
				Result(31 downto 0) <= r_sll;
				--<= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) sll to_integer(unsigned(inputB))) );

			when OPCODE_SRL => r_srl <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) srl to_integer(unsigned(inputB))) );
				Result(31 downto 0) <= r_srl;
				-- <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) srl to_integer(unsigned(inputB))) );

			when OPCODE_NOR =>r_nor <= not(inputA or inputB);
				Result(31 downto 0) <= r_nor;


			when OPCODE_ROR => r_ror <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) ror to_integer(unsigned(inputB))) );
				Result(31 downto 0) <= r_ror;
				--r_ror <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) ror to_integer(unsigned(inputB))) );

			when OPCODE_ROL => r_rol <= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) rol to_integer(unsigned(inputB))) );
				Result(31 downto 0) <= r_rol;
				--<= std_logic_vector(to_stdlogicvector(to_bitvector(std_logic_vector(inputA)) rol to_integer(unsigned(inputB))) );
			
			when OPCODE_FADD => 
				Result(31 downto 0) <= r_fadd;
			
			when OPCODE_FSUB =>
				Result(31 downto 0) <= r_fsub;

			when OPCODE_FMULT =>
				Result(31 downto 0) <= r_fmult;

			--when OPCODE_FDIV => 
			--	Result(31 downto 0) <= signed(r_fdiv);

			when others =>
				Result <= (others => '0');	
		end case;
	     end if;
          end if;
	end process;

end BEHAVIORAL;

