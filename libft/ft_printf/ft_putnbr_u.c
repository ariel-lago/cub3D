/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:54 by alago-ga          #+#    #+#             */
/*   Updated: 2025/07/14 14:12:29 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	char	digit;
	int		len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(n / 10);
	digit = (n % 10) + '0';
	write (1, &digit, 1);
	return (len + 1);
}
