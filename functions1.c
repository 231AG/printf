#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - Prints an unsigned number in an octal 
 *Notationa ful
 * @types: the list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  The active flags calculator
 * @width: width
 * @precision: The specifies the precision
 * @size: It specifies the size
 * Return: Number of characters to be ouput
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: The list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  The active flags calculator
 * @width: The width
 * @precision: The precision specifier
 * @size: It specifies the size
 * Return: the number of characters to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: The list a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  The active flags calculator
 * @width: get width
 * @precision: The precison specifies
 * @size: It specifies the size
 * Return: the umber of charactres to be ouput
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Prints a hexadecimal number in lowercase or uppercase
 * @types: The list of arguments
 * @map_to: An Array values of the map
 * @buffer: The buffer array to handle the print
 * @flags:  this is an active flags calculator
 * @flag_ch: The current active flags calculator
 * @width: Get the width
 * @precision: The precision specifier
 * @size: This specifies the isze
 * Return: The number of characters to be output
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
