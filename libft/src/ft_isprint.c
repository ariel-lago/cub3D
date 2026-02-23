/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:30:36 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/12 15:56:41 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_isprint('a'));
	printf("%i", ft_isprint('0'));
	printf("%i", ft_isprint(0x90));
	printf("%i", ft_isprint('{'));
	return (0);
}*/
