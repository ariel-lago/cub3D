/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:21:26 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/26 23:51:15 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* 
#include <stdio.h>
#include <ctype.h>

char	my_f(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (char)ft_toupper((unsigned char)c);
    return c;
}

int	main(void)
{
    char	*original = "nice nice very nice!";
    char	*result;

    result = ft_strmapi(original, my_f);
    if (result)
    {
        printf("Original: %s\n", original);
        printf("Result:   %s\n", result);
        free(result);
    }
    return 0;
}*/
