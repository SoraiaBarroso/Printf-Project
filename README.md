# Printf_Project

Recreation of printf function.

The _printf function produces output according to a format, this function write its output to the stdout, the standard output stream.

%c: Prints a single character.

%s: Prints a string of characters.

%d: Prints signed integers.

%o: Prints unsigned octals.

%u: Prints unsigned decimals.

%x: Prints unsigned hexadecimals.

%p: Prints pointer argument is printed in hexadecimal.

-----------------------------------------------------------

Each conversion specification is introduced by the PERCENT character. After the PERCENT, the following appear in sequence:

-doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).

-c The int argument is converted to an unsigned char, and the resulting character is written.

-s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.

-p The void * pointer argument is printed in hexadecimal.
