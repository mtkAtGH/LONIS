/*
 * This Specification is invoked by LONIS.H
 * NAME: Alphanumeric-Mono-case-upper: mnemonic alphanum-mono-case-lowr  - Abbreviation:	MCL
 * Scope: Modulo(36) Alphanumeric character set with value ranges "[0-9a-z]"
 * Ordinal range:
 * 		C:en/US.ASC "[0-9]" : c:en/US.int 48 <= ordinal <=  57;
 * 		C:en/US.ASC "[a-z]" : c:en/US.int 97 <= ordinal <= 122;
 * 		
 * Integral range:
 * 		C:en/US.ASC => C:en/US/LONIS.MCL
 * 		Binding: 'a' - '0' := 10
 *
 * Conversion:	INPUT:C:en/US.ASC to OUTPUT:C:en/US.int
 * 		C:en/US.int  :=	C:ASC_TO_MCL(input_byte){ 
 * 			C:en/US.char c = INPUT(C:en/US.ASC( input_byte.Ordinal() ));
 * 			if(c>='0'&&c<='9') return  OUTPUT(0+c-'0');
 * 				else
 * 			if(c>='a'&&c<='z') return OUTPUT(10+c-'a');
 *
 * 		C:}
 * 		
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 * 		C:en/US.char  :=	C:MCL_TO_ASC(input_integral){ 
 * 			C:en/US.int inp_int = INPUT(C:en/US.int( input_integral ));
 * 			if(inp_int%36>=10) return  OUTPUT((inp_int%36)+'a');
 * 				else
 * 			if(inp_int%36<10) return  OUTPUT((inp_int%36)+'0');
 *
 * Hash Key Lookup
 * 		ORDINAL
 * 	 	C:en/US/LONIS.MCL	C:en/US.ASC
 * 	 	0			'0'
 * 	 	..	...		...
 * 	 	9			'9'
 * 	 	10			'a'
 * 	 	..	...		...
 * 	 	35			'z'
*/
