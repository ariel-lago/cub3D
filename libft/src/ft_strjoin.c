/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:48:25 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/22 19:31:15 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*join;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	join = (char *)malloc(len);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, len);
	ft_strlcat(join, s2, len);
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "fin de";
	char	*s2 = " semana";
	char	*join;

	join = ft_strjoin(s1, s2);
	if (join == NULL)
	{
		printf("Error\n");
		return (1);
	}
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("join: %s\n", join);
	free(join);
	return (0);
}*/
