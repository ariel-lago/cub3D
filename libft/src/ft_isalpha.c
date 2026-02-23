/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:43:14 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/12 15:07:48 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("p: %i\n", ft_isalpha('p'));
	printf("P:%i\n", ft_isalpha('P'));
	printf("A:%i\n", ft_isalpha('A'));
	printf("z:%i\n", ft_isalpha('z'));
	printf("0:%i\n", ft_isalpha(0));
	printf(",:%i\n", ft_isalpha(','));
	printf(" :%i\n", ft_isalpha(' '));
	return (0);
}*/
