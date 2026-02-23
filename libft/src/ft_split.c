/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:50:45 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/27 15:36:01 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_words(const char *s, char c)
{
	int	count;
	int	wordflag;

	count = 0;
	wordflag = 0;
	while (*s)
	{
		if (*s != c && wordflag == 0)
		{
			wordflag = 1;
			count++;
		}
		else if (*s == c)
			wordflag = 0;
		s++;
	}
	return (count);
}

static size_t	ft_wlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_freesplit(char **array, size_t windex)
{
	size_t	i;

	i = 0;
	while (windex > i)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	windex;

	i = 0;
	windex = 0;
	array = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!array || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			array[windex] = ft_substr(s, i, ft_wlen(&s[i], c));
			if (!array[windex])
				return (ft_freesplit(array, windex), NULL);
			while (s[i] && s[i] != c)
				i++;
			windex++;
		}
	}
	array[windex] = NULL;
	return (array);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("no se, la verdad que itoa me parecio harder", ' ');
	if (!result)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/
