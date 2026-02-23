/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:11:26 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 17:08:37 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("0:%i\n", ft_isalnum('0'));
	printf("9:%i\n", ft_isalnum('9'));
	printf("!:%i\n", ft_isalnum('!'));
	printf("y:%i\n", ft_isalnum('y'));
	printf("I:%i\n", ft_isalnum('I'));
	return (0);
}*/
