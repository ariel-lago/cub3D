/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:07:25 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 17:11:53 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0'
			&& (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
    const char	haystack[] = "una aguja en un pajar";
    const char	needle[] = "aguja";
    char		*result;

    result = ft_strnstr(haystack, needle, 20);
    if (result)
        printf("Found :-) %s\n", result);
    else
        printf("Not found :-(\n");

    return (0);
}*/
