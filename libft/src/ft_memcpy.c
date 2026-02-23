/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:16:27 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/27 16:34:08 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pd;
	const unsigned char	*ps;

	if (!dest && !src)
		return (NULL);
	i = 0;
	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
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
	ft_memcpy(sd, ss, 2);
	printf("new dest:%s\n", sd);
	return (0);
}*/
