/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:04:02 by alago-ga          #+#    #+#             */
/*   Updated: 2025/07/14 14:12:56 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		return (ft_putnbr_u((unsigned int)n) + 1);
	}
	return (ft_putnbr_u((unsigned int)n));
}
