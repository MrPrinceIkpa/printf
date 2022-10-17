#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	printer printer;
	int i = 0;
	int characters_prt = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			characters_prt++;
		}
		if (!format[i])
			return (characters_prt);
		if (format[i] == '%' && _strlen(format) == 1)
			return (-1);
		printer = _get_print(&format[i + 1]);
		if (printer.specifier != NULL)
		{
			characters_prt += printer.run(args);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (characters_prt);

		_putchar(!format[i + 1]);
		characters_prt++;

		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);
	return (characters_prt);
}
