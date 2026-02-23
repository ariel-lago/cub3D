/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:33:11 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 17:03:19 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		a;

	p = (const unsigned char *)s;
	a = (unsigned char)c;
	while (n > 0)
	{
		if (*p == a)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*str = "wait a minute";

	printf("string: %s\n", str);
	printf("string from char: %s\n", (char *)ft_memchr(str, 'i', 6));
	return (0);
}*/
