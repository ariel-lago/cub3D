/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:06:25 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/22 15:20:43 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "telenovelas";
	char dst[20];
	ft_strlcpy(dst, src, 10);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dst);
	printf("Length of source: %zu\n", ft_strlcpy(dst, src, 10));
	return 0;
}*/
