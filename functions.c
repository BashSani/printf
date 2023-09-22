#include "main.h"

/**
 * print_char - Print char
 * @types: List
 * @buffer: Buffer
 * @u: Flags
 * @v: Width
 * @w: Precision
 * @x: Size
 * Return: 0
 */

int print_char(va_list types, char buffer[], int u, int v, int w, int x)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, u, v, w, x));
}
/**
 * print_string - Print string
 * @types: List
 * @buffer: Buffer
 * @u: Flags
 * @v: Width
 * @w: Precision
 * @x: Size
 * Return: 0
 */
int print_string(va_list types, char buffer[], int u, int v, int w, int x)
{
	int length = 0, r;
	char *str = va_arg(types, char *);
	
	UNUSED(buffer);
	UNUSED(u);
	UNUSED(v);
	UNUSED(w);
	UNUSED(x);
	if (str == NULL)
	{
		str = "(null)";
		if (w >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (w >= 0 && w < length)
		length = w;
	if (v > length)
	{
		if (u & F_MINUS)
		{
			write(1, &str[0], length);
			for (r = v - length; r > 0; r--)
				write(1, " ", 1);
			return (v);
		}
		else
		{
			for (r = v - length; r > 0; r--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (v);
		}
	}
	return (write(1, str, length));
}
/**
 * print_percent - Print percent
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @u: Flags
 * @v: Width
 * @w: Precision 
 * @x: Size
 * Return: 0
 */
int print_percent(va_list types, char buffer[], int u, int v, int w, int x)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(u);
	UNUSED(v);
	UNUSED(w);
	UNUSED(x);
	return (write(1, "%%", 1));
}
/**
 * print_int - Print int
 * @types: Arguments
 * @buffer: Buffer
 * @u: Flags
 * @v: Width.
 * @w: Precision
 * @x: Size
 * Return: 0
 */
int print_int(va_list types, char buffer[], int u, int v, int w, int x)
{
	int r = z - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	
	n = convert_size_number(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[z - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[r--] = (num % 10) + '0';
		num /= 10;
	}
	r++;
	return (write_number(is_negative, r, buffer, u, v, w, x));
}
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @u: Flags
 * @v: Width.
 * @w: Precision
 * @x: Size
 * Return: 0
 */
int print_binary(va_list types, char buffer[], int u, int v, int w, int x)
{
	unsigned int n, m, r, sum;
	unsigned int a[32];
	int count;
	
	UNUSED(buffer);
	UNUSED(u);
	UNUSED(v);
	UNUSED(w);
	UNUSED(x);
	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (r = 1; r < 32; r++)
	{
		m /= 2;
		a[r] = (n / m) % 2;
	}
	for (r = 0, sum = 0, count = 0; r < 32; r++)
	{
		sum += a[r];
		if (sum || r == 31)
		{
			char o = '0' + a[i];
			
			write(1, &o, 1);
			count++;
		}
	}
	return (count);
}
