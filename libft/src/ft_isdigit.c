/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:52:30 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/12 13:10:32 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
int	main(void)
{
	printf("0:%i\n", ft_isdigit('0'));
	printf("9:%i\n", ft_isdigit('9'));
	printf("3:%i\n", ft_isdigit('3'));
	printf("y:%i\n", ft_isdigit('y'));
	printf("I:%i\n", ft_isdigit('I'));
	return (0);
}*/
