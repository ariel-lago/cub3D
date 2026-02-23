/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:55:53 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/22 14:42:37 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str1 = "hoy no es domingo";
	char	*str2;

	str2 = ft_strdup(str1);
	if (str2 == NULL)
	{
		printf("Error\n");
		return (1);
	}
	printf("s1: %s\n", str1);
	printf("s2: %s\n", str2);
	free(str2);
	return (0);
}*/
