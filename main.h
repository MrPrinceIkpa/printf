#ifndef _PRINTF_CUSTOM_H_
#define _PRINTF_CUSTOM_H_


#include <stdarg.h>
#include <stdlib.h>

/**
 * struct printer - the structure for printing to stdout, given a specifier
 * @specifier: the specifier recognized by this printer (without the %)
 * @run: the function to run when this printer is invoked
 */

typedef struct printer
{
	char *specifier;
	int (*run)(va_list);
} printer;

printer _get_print(const char *specifier);
int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list);
int _print_str(va_list);

#endif /* _PRINTF_CUSTOM_H_ */

