/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:17:13 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/22 12:54:55 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int		*arr;
	size_t	count;
	size_t	size;
	size_t	i;

	count = 5;
	size = sizeof(int);
	i = 0;
	arr = ft_calloc(count, size);
	if (arr == NULL)
	{
		printf("Error\n");
		return (1);
	}
	while (i < count)
	{
		i++;
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
	return (0);
}*/
