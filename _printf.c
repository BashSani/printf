#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - function
 * @format: format
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int r, s = 0, t = 0;
	int u, v, w, x, buff_ind = 0;
	va_list y;
	char z;

	if (format == NULL)
		return (-1);

	va_start(y, format);

	for (r = 0; format && format[r] != '\0'; r++)
	{
		if (format[r] != '%')
		{
			buffer[buff_ind++] = format[r];
			if (buff_ind == z)
				print_buffer(buffer, &buff_ind);
			t++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			u = get_u(format, &r);
			v = get_v(format, &r, y);
			w = get_w(format, &r, y);
			x = get_x(format, &r);
			++r;
			s = handle_print(format, &r, y, buffer, u, v, w, x);
			if (s == -1)
				return (-1);
			t += s;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(y);

	return (t);
}

/**
 * print_buffer - Print buffer
 * @buffer: Array
 * @buff_ind: Length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

