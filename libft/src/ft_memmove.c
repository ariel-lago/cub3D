/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:04:31 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 17:09:13 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		pd = (unsigned char *)dest;
		ps = (const unsigned char *)src;
		i = n;
		while (i > 0)
		{
			i--;
			pd[i] = ps[i];
		}
	}
	return (dest);
}

/* 
#include <stdio.h>

int	main(void)
{
	char	sd[] = "tooth";
	char	ss[] = "blue";

	printf("orig dest:%s\n source:%s\n", sd, ss);
	ft_memmove(sd, ss, 2);
	printf("new dest:%s\n", sd);
	return (0);
}*/
