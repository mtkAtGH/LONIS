/* Invoked in LONIS.H
 * A mappping of all printable text including whitespace applies
 *
 * NAME: Lexical-Nonumeric-printable-text: mnemonic lexical-text  - Abbreviation:	LXT
 * Scope: Modulo(95) Alphanumeric character set with value ranges "[ - |]", the entire six
 * hexadecimal blocks of ASC 1965 assignments up to ASC = 126. Value ASC 127 designated [END]
 * is not printable hence the modulo(95) instead of expected modulo(96).
 *
 * Ordinal range: Is only useful to typecase character assignment since the mathematical operator
 * symbols required to maniulate numeric values are in-band text and not available. Ordinal range
 * for out-of-band numeric operation are as follows:
 *	ASC (1965)
 *	0  [UNPRINTABLES]
 *	16 [UNPRINTABLES]
 *	32 ‘ ‘ ‘!’ ‘”’ ‘#’ ‘$’ ’%’ ‘&’ ‘’’ ‘(‘ ‘)’ ‘*’ ‘+’ ‘’’ ‘-’ ‘.’ ‘/’
 *	48 ‘0’ ‘1’ ‘2’ ‘3’ ‘4’ ‘5’ ‘6’ ‘7’ ‘8’ ‘9’ ‘:’ ‘;’ ‘<’ ‘=’ ‘>’ ‘?’
 *	64 ‘`’ ‘A’ ‘B’ ‘C’ ‘D’ ‘E’ ‘F’ ‘G’ ‘H’ ‘I’ ‘J’ ‘K’ ‘L’ ‘M’ ‘N’ ‘O’
 *	80 ‘P’ ‘Q’ ‘R’ ‘S’ ‘T’ ‘U’ ‘V’ ‘W’ ‘X’ ‘Y’ ‘Z’ ‘[‘ ‘~’ ‘]’ ‘^’ ‘_’
 *	96 ‘@’ ‘a’ ‘b’ ‘c’ ‘d’ ‘e’ ‘f’ ‘g’ ‘h’ ‘i’ ‘j’ ‘k’ ‘l’ ‘m’ ‘n’ ‘o’
 *	112 ‘p’ ‘q’ ‘r’ ‘s’ ‘t’ ‘u’ ‘v’ ‘w’ ‘x’ ‘y’ ‘z’ ‘{‘ ‘¬’ ‘}’ ‘|’ 
 * 	Block range:	C:en/US.ASC "[ -/]"	:en/US.int  32 <= ordinal <= 47;
 * 	Block range:	C:en/US.ASC "[0-?]"	:en/US.int  48 <= ordinal <= 63;
 * 	Block range:	C:en/US.ASC "[`-O]"	:en/US.int  64 <= ordinal <= 79;
 * 	Block range:	C:en/US.ASC "[P-_]"	:en/US.int  80 <= ordinal <= 95;
 * 	Block range:	C:en/US.ASC "[@-o]"	:en/US.int  96 <= ordinal <= 111;
 * 	Block range:	C:en/US.ASC "[p-|]"	:en/US.int 112 <= ordinal <= 126;
 * */
