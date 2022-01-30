/*
 * This Specification is invoked by LONIS.H
 * NAME: Hexadecimal-Mono-case-upper: mnemonic hex-mono-case-uppr  - Abbreviation:	HXU
 * Scope: Modulo(16) Hexadecimal character set with value ranges "[0-9A-F]"
 * Ordinal range:
 * 		C:en/US.ASC "[0-9]" : c:en/US.int 48 <= ordinal <= 57;
 * 		C:en/US.ASC "[A-F]" : c:en/US.int 65 <= ordinal <= 70;
 * 		
 * Integral range:
 * 		C:en/US.ASC => C:en/US/LONIS.HXU
 * 		Binding: '0' - '0' := 0
 * 		Binding: 'A' - '0' := 10
 *
 * Conversion:	INPUT:C:en/US.ASC to OUTPUT:C:en/US.int
 * 		C:en/US.int  :=	C:ASC_TO_HXU(input_byte){ 
 * 			C:en/US.char c = INPUT(C:en/US.ASC( input_byte.Ordinal() ));
 * 			if(c>='0'&&c<='9') return  OUTPUT(0+c-'0');
 * 				else
 * 			if(c>='A'&&c<='F') return OUTPUT(10+c-'A');
 *
 * 		C:}
 * 		
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 * 		C:en/US.char  :=	C:HXU_TO_ASC(input_integral){ 
 * 			C:en/US.int inp_int = INPUT(C:en/US.int( input_integral ));
 * 			if(inp_int%16>=10&&inp_int%16<16) return  OUTPUT((inp_int%16)+'A');
 * 				else
 * 			if(inp_int%16<10) return  OUTPUT((inp_int%16)+'0');
 *
 * Hash Key Lookup
 * 		ORDINAL
 * 	 	C:en/US/LONIS.HXU	C:en/US.ASC
 * 	 	0			'0'
 * 	 	..	...		...
 * 	 	9			'9'
 * 	 	10			'A'
 * 	 	..	...		...
 * 	 	15			'F'
*/
