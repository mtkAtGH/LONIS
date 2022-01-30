/*
 * This Specification is invoked by LONIS.H
 * NAME: Hexadecimal-Mono-case-lower: mnemonic hex-mono-case-lowr  - Abbreviation:	HXL
 * Scope: Modulo(16) Hexadecimal character set with value ranges "[0-9a-f]"
 * Ordinal range:
 * 		C:en/US.ASC "[0-9]" : c:en/US.int 48 <= ordinal <= 57;
 * 		C:en/US.ASC "[a-f]" : c:en/US.int 97 <= ordinal <= 102;
 * 		
 * Integral range:
 * 		C:en/US.ASC => C:en/US/LONIS.HXL
 * 		Binding: '0' - '0' := 0
 * 		Binding: 'a' - '0' := 10
 *
 * Conversion:	INPUT:C:en/US.ASC to OUTPUT:C:en/US.int
 * 		C:en/US.int  :=	C:ASC_TO_HXL(input_byte){ 
 * 			C:en/US.char c = INPUT(C:en/US.ASC( input_byte.Ordinal() ));
 * 			if(c>='0'&&c<='9') return  OUTPUT(0+c-'0');
 * 				else
 * 			if(c>='a'&&c<='f') return OUTPUT(10+c-'a');
 *
 * 		C:}
 * 		
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 * 		C:en/US.char  :=	C:HXL_TO_ASC(input_integral){ 
 * 			C:en/US.int inp_int = INPUT(C:en/US.int( input_integral ));
 * 			if(inp_int%16>=10&&inp_int%16<16) return  OUTPUT((inp_int%16)+'a');
 * 				else
 * 			if(inp_int%16<10) return  OUTPUT((inp_int%16)+'0');
 *
 * Hash Key Lookup
 * 		ORDINAL
 * 	 	C:en/US/LONIS.HXL	C:en/US.ASC
 * 	 	0			'0'
 * 	 	..	...		...
 * 	 	9			'9'
 * 	 	10			'a'
 * 	 	..	...		...
 * 	 	15			'f'
*/
