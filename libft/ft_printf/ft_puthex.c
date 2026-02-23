/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:06:52 by alago-ga          #+#    #+#             */
/*   Updated: 2025/07/14 14:15:54 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	char	*x;
	int		len;

	x = "0123456789abcdef";
	len = 0;
	if (c == 'X')
		x = "0123456789ABCDEF";
	if (n > 15)
		len += ft_puthex(n / 16, c);
	write(1, &x[n % 16], 1);
	return (len + 1);
}
