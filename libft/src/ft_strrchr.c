/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:54:16 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 17:02:42 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		l;

	l = ft_strlen(str);
	while (1)
	{
		if (str[l] == (char)c)
			return ((char *)str + l);
		if (l == 0)
			break ;
		l--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[] = "ya son mas de las cuatro";

	printf("str = %s\n", str);
	printf("postfunction= %s", ft_strrchr(str, 'y'));
	return (0);
}*/
