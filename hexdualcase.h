
/*
 * This Specification is invoked by LONIS.H
 * NAME: Bihex-dualcase-decimal: mnemonic bi-hexa-decimal  - Abbreviation:	BHD
 * Scope: Modulo(22) Alphanumeric character set with value ranges "[0-9A-Fa-f]"
 * Ordinal range:
 * 		C:en/US.ASC "[0-9]" : c:en/US.int 48 <= ordinal <= 57;
 * 		C:en/US.ASC "[A-F]" : c:en/US.int 65 <= ordinal <= 70;
 * 		C:en/US.ASC "[a-f]" : c:en/US.int 94 <= ordinal <= 99;
 * 		
 * Integral range:
 * 		C:en/US.ASC => C:en/US/LONIS.DCT
 * 		Binding: '0' - '0' := 0
 * 		Binding: 'A' - '0' := 10
 * 		Binding: 'a' - '0' := 16
 *
 * Conversion:	INPUT:C:en/US.ASC to OUTPUT:C:en/US.int
 * 		C:en/US.int  :=	C:ASC_TO_DCT(input_byte){ 
 * 			C:en/US.char c = INPUT(C:en/US.ASC( input_byte.Ordinal() ));
 * 			if(c>='0'&&c<='9') return  OUTPUT(0+c-'0');
 * 				else
 * 			if(c>='A'&&c<='F') return OUTPUT(10+c-'A');
 * 				else
 * 			if(c>='a'&&c<='f') return OUTOUT(16+c-'a');
 *
 * 		C:}
 * 		
 * Conversion:	INPUT:C:en/US.int to OUTPUT:C:en/US.ASC
 * 		C:en/US.char  :=	C:DCT_TO_ASC(input_integral){ 
 * 			C:en/US.int in_in = INPUT(C:en/US.int( input_integral ));
 * 			if(in_in%22>=16) return  OUTPUT(in_in%22+'a');
 * 				else
 * 			if(in_in%22>=10&&in_in%22<16) return  OUTPUT((in_in%22)+'A');
 * 				else
 * 			if(in_in%22<10) return  OUTPUT((in_in%22)+'0');
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
 * 	 	15			'F'
 * 	 	16			'a'
 * 	 	..	...		...
 * 	 	21			'f'
*/

