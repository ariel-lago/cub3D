/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:08:56 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/12 15:29:39 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("0:%i\n", ft_isascii('0'));
	printf("a:%i\n", ft_isascii('a'));
	printf("&:%i\n", ft_isascii('&'));
	printf("ñ:%i\n", ft_isascii(0xF1));
	printf("あ:%i\n", ft_isascii(0x3042));
	return (0);
}*/
