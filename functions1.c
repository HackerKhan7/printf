#include "main.h"

/** Print an unsigned number **/
/**
 * print_unsigned - To Print an unsigned number
 * @types: List a of arguments
 * @buffer: To Buffer an array to handle print
 * @flags:  To Calculate the active flags
 * @width: for getting Width
 * @precision: Precision specifications
 * @size: Specifying Size 
 * Return: Returning  the Number of chars to be printed
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

/** Printing an unsigned number in octal notation **/
/**
 * print_octal - Printing an unsigned number in octal notation
 * @types: List a of arguments
 * @buffer: To Buffer an array to handle print
 * @flags:  To Calculate the active flags
 * @width: for getting Width
 * @precision: Precision specifications
 * @size: Specifying Size 
 * Return: Returning  the Number of chars to be printed
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

/** Printing an unsigned number in hexadec notation **/
/**
 * print_hexadecimal - Printing an unsigned number in hexadec notation
 * @types: List a of arguments
 * @buffer: To Buffer an array to handle print
 * @flags:  To Calculate the active flags
 * @width: for getting Width
 * @precision: Precision specifications
 * @size: Specifying Size 
 * Return: Returning  the Number of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** Printing an unsigned number in upper hexadecimal notation **/
/**
 * print_hexa_upper - Printing an unsigned number in upper hexadecimal notation
 * @types: List a of arguments
 * @buffer: To Buffer an array to handle print
 * @flags:  To Calculate the active flags
 * @width: for getting Width
 * @precision: Precision specifications
 * @size: Specifying Size 
 * Return: Returning  the Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** Printing a hexadecimal number in lower or upper **/
/**
 * print_hexa - Printing a hexadecimal number in lower or upper
 * @types: List a of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get the width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specifications
 * Return: Number of chars printed
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
