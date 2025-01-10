/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:40:47 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/25 14:38:40 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchr((char)va_arg(args, int));
	else if (format == 'i' || format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == '%')
		len += ft_putchr('%');
	else if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 2);
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'u')
		len += ft_putnbr_uns(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
			{
				len += ft_handle_format(*format, args);
				format++;
			}
		}
		else
		{
			ft_putchr(*format);
			len++;
			format++;
		}
	}
	va_end(args);
	return (len);
}

// int	main()
// {
// 	char c = 'A';
// 	printf("printf: Character: %c\n", c);
// 	ft_printf("ft_printf: Character: %c\n", c);

// 	char *str = "Hello, World!";
// 	printf("printf: String: %s\n", str);
// 	ft_printf("ft_printf: String: %s\n ", str);

// 	void *ptr = "16";
// 	printf("printf: Pointer: %p\n", ptr);
// 	ft_printf("ft_printf: Pointer: %p\n ", ptr);

// 	int num = 42;
// 	printf("printf: Integer: %d\n", num);
// 	ft_printf("ft_printf: Integer: %d\n", num);

// 	int neg_num = -46442;
// 	printf("printf: Negative Integer: %d\n", neg_num);
// 	ft_printf("ft_printf: Negative Integer: %d\n", neg_num);

// 	printf("printf: Unsigned Integer: %u\n", u_num);
// 	ft_printf("ft_printf: Unsigned Integer: %u\n", u_num);

// 	unsigned int hex_num = 255;
//	printf("printf: Hexadecimal (lowercase): %x\n", hex_num);
// 	ft_printf("ft_printf: Hexadecimal (lowercase): %x\n", hex_num);

// 	printf("printf: Hexadecimal (uppercase): %X\n", hex_num);
// 	ft_printf("ft_printf: Hexadecimal (uppercase): %X\n", hex_num);

// 	ft_printf("Null String: %s\n", NULL);

// 	return 0;
// }