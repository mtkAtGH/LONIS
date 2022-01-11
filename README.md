# LONIS
Lexical Open Numerics Interchange Scheme
/*
 * 	LONIS:	A Lexical Open	Numerics Interchange Scheme
 * 	Origins:
 * 	"A number of user interaction settings have been identified in the interpretive APA(X)
 * 	Arbitrary Precision Arithmetic Expression experimental shell environment (see mtkAtGH/apax).
 *
 * 	Expressions in (X) are rendered in plain text numeric character, in mathematical operator 
 * 	symbols or in alphanumeric characters for variable names and other reference identifiers."
 *
 *	Locale:
 	"In the default numeric context setting APA(X) has a decimal numeric system with implied RADIX=10
  	The default character interchange codes employs ASCII. As a result the default native Locale
	inherited by APA(X) is en/US with C-Language data primitives. Specifically C:en/US Locale mandates
	numerical separators '.' for Fractions, and ',' for successive Integral Thousands.
 
 	But APA(X) readily changes RADIX to any positive C-Language integer value, and APA(X)
	also introduces the need for specialised display constraints for such non-decimal RADIX values"

 *	The APA(X) I/O options description for Radix manipulation:
 *	Radix:
		"The basis of the fixed-radix number system i.e. other than the factorial
		format may be changed from the decimal default value of 10. Valid values range
		from 2 to 2147483598 (on 64 bit architectures)."
 *	Representation:
		"A number is written as a register of radix place values in radix.power(n) value string
		sequence. For legibility, each place value on the register is right-justified and zero-padded
		in the space required to hold the value RADIX-1."
 *	Constraints:
		"Inputs are declared in radix 10 using the default ASCII-compliant C:en/US decimal number system."
 *	Cautions:
		"The apparent precision increases roughly with the log of the radix but the computation speed drops
		drastically, especially at high radices. The default setting is RADIX= 10"
 *	Interpretation:
 		"The phrase ’zero‐padded and right justified’ appears in the APA(X) ?r Radix query. What it means
		is that a register position with say RADIX 200 will represent all 200 place values like this:

                              ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----
                              |                                              |
                              |    000  001  002  ... 011  012  ... 198 199  |
                              |    ‐‐‐, ‐‐‐, ‐‐‐, ... ‐‐‐, ‐‐‐, ... ... ‐‐‐  |
                              |    200  200  200  ... 200  200  ... 200 200  |
                              |                                              |
                              ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----
 		
 		For example, so as to distinguish a RADIX 200 first value 1/200 from a second value  11/200 
		or even the  last  value  111/200 in a number such as numerator string '000.001011111' Base 200
		which is expression '1/200+11/200+111/200' = 0.615 in the normal Base 10 DECIMAL notation (Source:
	       	apax man(1) page and apa man(3) manuscript help pages).

                   	      ‐‐‐‐‐‐‐-‐‐‐‐‐‐‐‐‐‐------		RADIX 200:	RADIX 10:
                              |                       |
                              |  000   001  011  111  |
                              |  --- . ‐‐‐  ‐‐‐  ‐‐‐  |		000.001011111	= 0.615
                              |  200   200  200  200  |
                              |                       |
                              ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-----‐‐-
 		
"
*	Implementation:		
 		"An arbitrary numerical value shall consist of a series of integer-sized place positions
 		where each place value is held by a C-Language integer, such that the entire value
		is contained in a 'string' of such integers, of length given by prevailing 'precision'.

		Say there are two operand registers with place value integers, say 'oprnd1' and 'oprnd2' in
		the usual arithmetic context includes a result register place value 'reslt3', and an intermediate
		carry overflow register 'ocarry', such that the result of a summation 'summ' or multiplication
		'prod' requires rendering of the eventual result place value in quoted C-language syntax:"
 *	Declaration of values:
			"int oprnd1, oprnd2, summ, prod, ocarry, reslt3;"
 *	Operation:
			"summ = oprnd1+oprnd2;"
		or
			"prod = oprnd1*oprnd2;"

			"ocarry = summ/radix';"
		or
			"ocarry = prod/radix;"
	and result:
			"reslt3 = summ%radix;"
		or
			"reslt3 = prod%radix;"
 *
 		"The C-syntax operations '+', '-', '*', '/', and '%' invoke the arithmetic unit of the host
 		machine with the proviso that thier ALU overflow is captured by as many 'ocarry' place values
		as needed to preserve the result."
	Display:
		" The result is displayed as the numerator strings, zero-padded and right-justified .The APA(X)
		reference implementation for displaying the result place value by place value with right padding
		may be achieved by a rignt to left  place value extraction and their numerator values may be
		rendered for display onto their ASC ordinal codes referenced on '0' character value:"
 *	Declaration of registers:
			"int *ans, *padded, *run, *int1ptr();"
		
			"ans = lftpad(ans,sum%radix+'0');"
		or
			"ans = lftpad(ans,prod%radix+'0');"
	
 *	Zero padded right-justified Renderer:

			"int *lftpad(str,chr)
			int *str;
			int chr;
			{
				int istrln(), *padded, *run, *int1ptr();
				int slen = istrln(str);
				padded = int1ptr(slen+2);
				run = &padded[slen+1];
				while(*str++);
				while(run>=&padded[1]) *run-- = *--str;
				*padded = chr;
				free(str);
				return padded;
			}"
	This reference implementation uses C-strings like methods istrln() matching string.h strlen()
	and istr1ptr() a stdlib.h calloc() wrapper for allocating an integer array 'int *padded=istr1ptr()'. 
	It is possible to achieve the same redition using C stdio.h I/O formatters as long as radix 10
  is the destination display. Should non-decimal display be desired. The ASC Ordinal offset adjustment 
	"+'0'" shown above shall require modification for alternate character sets such as high "[0-9A-Z]"
	or low 'monocasedecimal' "[0-9a-z]" or alphanumerics, each modulo(36), dual case 'duocasedecimal' 
  "[0-9A-z]"  modulo(62) or 'extratext' modulo(97) of all printable keyboard symbols, with white-space and
  punctuation. Such single character place value symbols mimick the Hexadecimals across the keyboard,
  and are the lexical text only interchange benchmark 'lextxt.h' for extending 'C:stdio.h' to all printable
  symbols under this scheme.
	
	NB:Although out of scope, the place value construction described here is relevant to 'factorial'
	format registers for exact arithmetic using rational number operands as discussed elsewhere in APA(X).
	* NB2 This document is written in C:en/US using a 'vi derivative 'vim'.
*/
