#include <stdarg.h>
#include <stdio.h>
#include <sys/cdefs.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//writes a character
int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

//writes a string
int my_putstr(char* str)
{  
    int i = 0;
    while(str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return *str;
}

//writes octal, octal numbers are Numbers of base 8, and they are they use numbers between 0 and 7
int my_putoctal(unsigned int nbr)
{     
    int len = 0;

    //stores remainder 
    if(nbr >= 7) 
        len += my_putoctal(nbr / 8);

    return (len + my_putchar(nbr % 8 + '0'));  
}

//decimal
int my_putdec(int nbr)
{ 
    int i = 0;
    if (nbr < 0){
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr >= 10){
        i += my_putdec(nbr / 10);
        i += my_putdec(nbr % 10);
    }
    else{
        my_putchar(nbr + '0');
        i++;
    }
    return (i);
}

//hexadecimal
int my_puthex(unsigned int nbr)
{
    int len = 0;
    if(nbr > 15)
        len += my_puthex(nbr / 16); 
    if(nbr % 16 < 10)
        return(len + my_putchar(nbr % 16 + '0'));
    else
        return (len + my_putchar(nbr % 16 + 'a' - 10));
}

//unsigned decimal, variable can hold only a positive value
int my_putud(unsigned int nbr)
{
    int len = 0;
    if (nbr > 9)
        len += my_putud(nbr / 10);
    return (len + my_putchar(nbr % 10 + '0'));   
}


int my_printf(char * restrict format, ...){

    char *s, c; 
    unsigned int u; 
    int d; 
    intptr_t x;
    int len = 0;

    //handle the variable argument list.
    va_list arg_list; 

    //initializes the list with the arguments arg_list and arg.
    va_start(arg_list, format); 


    while(*format != '\0'){
    //Each conversion specification is introduced by the PERCENT character
    if(*format == '%')
    { 
        switch(*++format) 
        {
        case 'c':  //char arguments
            c = va_arg(arg_list, int);
            len += my_putchar(c);
            break;

        case 'd': //int-decimal arguments
            d = va_arg(arg_list, int); 
            len += my_putdec(d);
            break;

        case 'o': //octal
            u = va_arg(arg_list, unsigned int); 
            len += my_putoctal(u);
            break;

        case 's': //String
            s = va_arg(arg_list, char*); 
            len += my_putstr(s);
            break;

        case 'x': //hexadecimal
            x = va_arg(arg_list, int); 
            len += my_puthex(x);
            break;

        case 'u': //unsigned decimal can hold only a positive value
            u = va_arg(arg_list, unsigned int);
            len += my_putud(u);
            break;

        case 'p': //pointer argument printed in hexadecimal.
            x = va_arg(arg_list, intptr_t);
            len += my_putstr("0x") + my_puthex(x);
            break;
        

        default:
            len += my_putchar('%');
     }
     format++;
    }
    if(*format != '%')
    {
        len += my_putchar(*format);
        format++;
    }
}
    va_end(arg_list);
    return (len);
} 


int main(){

    //my_printf("Hello, World! %s - %d - %c - %u - %o - %x - %p\n", "test", 42, 'a', 42, 42, 42, 42);
    //my_printf("Hi %o \n", 50);
    //my_printf("Hi %x \n", 50);
    //my_printf("Hi %u\n", -5);
    //my_printf("Hi %p\n", 50);
    return (0);
}
