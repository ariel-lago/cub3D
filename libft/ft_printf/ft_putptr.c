/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:14:38 by alago-ga          #+#    #+#             */
/*   Updated: 2025/07/14 15:07:47 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	if (!p)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	if (p == 0 || !p)
		return (write(1, "0", 1) + 2);
	else
		return (ft_puthex((unsigned long)p, 'x') + 2);
}
