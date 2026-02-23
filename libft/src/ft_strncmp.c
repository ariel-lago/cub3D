/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:42:15 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/15 20:51:07 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*s1 = "soleado";
	const char	*s2 = "soldado";

	printf("s1= %s\ns2= %s\n", s1, s2);
	printf("comparacion: %i\n", ft_strncmp(s1, s2, 4));
	printf("comparacion original: %i", strncmp(s1, s2, 4));
	return (0);
} */
