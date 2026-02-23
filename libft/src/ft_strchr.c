/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:23:28 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/15 16:48:25 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*p;
	char		ch;

	p = str;
	ch = (char)c;
	while (*p != '\0')
	{
		if (*p == ch)
			return ((char *)p);
		p++;
	}
	if (ch == '\0')
		return ((char *)p);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	str[] = "ya son mas de las cuatro";

	printf("str = %s\n", str);
	printf("postfunction= %s", ft_strchr(str, 'd'));
	return (0);
}*/
