/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:48:55 by alago-ga          #+#    #+#             */
/*   Updated: 2025/07/14 16:54:16 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char f, va_list args)
{
	if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (f == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (f == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	if (f == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 'x'));
	if (f == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 'X'));
	if (f == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (f == '%')
		return (write(1, "%", 1));
	else
	{
		write(1, "%", 1);
		write(1, &f, 1);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;
	int		formatlen;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			formatlen = ft_format(*format, args);
			if (formatlen >= 0)
				len += formatlen;
			format++;
		}
		else
		{
			write(1, format, 1);
			len++;
			format++;
		}
	}
	va_end(args);
	return (len);
}
