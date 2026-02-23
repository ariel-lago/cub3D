/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:32:06 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/26 13:30:25 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*subs;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
	{
		end--;
	}
	subs = ft_substr(s1, start, end - start); 
	return (subs);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = " & nice nice very nice & ";
	char *set = "  & * j";
	char *result;

	result = ft_strtrim(s1, set);
	printf("Original: '%s'\n", s1);
	printf("Trimmed: '%s'\n", result);
	free(result);
	return (0);
}*/
