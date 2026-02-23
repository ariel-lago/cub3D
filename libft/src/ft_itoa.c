/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:49:59 by alago-ga          #+#    #+#             */
/*   Updated: 2025/08/03 22:36:16 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*result;
	int		len;

	num = (long)n;
	len = ft_intlen(num);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		num = -num;
		result[0] = '-';
	}
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		len --;
		result [len] = (num % 10) + '0';
		num = num / 10;
	}
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
    int		tests[] = {0, 1, -1, 42, -42, 2147483647, -2147483648};
    int		i;
    char	*str;

    for (i = 0; i < 7; i++)
    {
        str = ft_itoa(tests[i]);
        printf("ft_itoa(%d) = \"%s\"\n", tests[i], str);
        free(str);
    }
    return (0);
}*/
