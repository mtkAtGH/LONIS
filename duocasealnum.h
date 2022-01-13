
/*
 * This Specification is invoked by LONIS.H
 * NAME: Alphanumeric-dual-case-text: mnemonic alphanum-dual-case-text  - Abbreviation:	DCT
 * Scope: Modulo(62) Alphanumeric character set with value ranges "[0-9a-z]"
 * Ordinal range:
 * 		C:en/US.ASC "[0-9]" : c:en/US.int 48 <= ordinal <= 57;
 * 		C:en/US.ASC "[A-Z]" : c:en/US.int 65 <= ordinal <= 90;
 * 		C:en/US.ASC "[a-z]" : c:en/US.int 97 <= ordinal <= 122;
 * 		
 * Integral range:
 * 		C:en/US.ASC => C:en/US/LONIS.DCT
 * 		Binding: '0' - '0' := 0
 * 		Binding: 'A' - '0' := 10
 * 		Binding: 'a' - '0' := 36
 *
 * Conversion:	INPUT:C:en/US.ASC to OUTPUT:C:en/US.int
 * 		C:en/US.int  :=	C:ASC_TO_DCT(input_byte){ 
 * 			C:en/US.char c = INPUT(C:en/US.ASC( input_byte.Ordinal() ));
 * 			if(c>='0'&&c<='9') return  OUTPUT(0+c-'0');
 * 				else
 * 			if(c>='A'&&c<='Z') return OUTPUT(10+c-'A');
 * 				else
 * 			if(c>='a'&&c<='z') return OUTOUT(36+c-'a');
 *
 * 		C:}
 * 		
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 * 		C:en/US.char  :=	C:DCT_TO_ASC(input_integral){ 
 * 			C:en/US.int in_in = INPUT(C:en/US.int( input_integral ));
 * 			if(in_in%62>=36) return  OUTPUT(in_in%62+'a');
 * 				else
 * 			if(in_in%62>=10&&in_in%62<36) return  OUTPUT((in_in%62)+'A');
 * 				else
 * 			if(in_in%62<10) return  OUTPUT((in_in%62)+'0');
 *
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 *
 * Hash Key Lookup
 * 		ORDINAL
 * 	 	C:en/US/LONIS.DCT	C:en/US.ASC
 * 	 	0			'0'
 * 	 	..	...		...
 * 	 	9			'9'
 * 	 	10			'A'
 * 	 	..	...		...
 * 	 	35			'Z'
 * 	 	36			'a'
 * 	 	..	...		...
 * 	 	61			'z'
*/
