#include "main.h"

/**
 * _get_print -  a function that selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @specifier: A pointer that holds the conversion specifier
 * Description: the function loops through the structs array
 * printers[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 *
 * Return: the printer found. if no valid printer exists,
 * a default NULL-based printer is returned
 */

printer _get_print(const char *specifier)
{
	int i;
	static printer printers[] = {
		{"c", _print_char},
		{"s", _print_str},
		{NULL, NULL}
	};

	for (i = 0; printers[i].specifier != NULL; i++)
	{
		if (*specifier == *(printers[i].specifier))
			break;
	}

	return (printers[i]);
}
