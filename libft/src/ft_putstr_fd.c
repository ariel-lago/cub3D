/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:51:40 by alago-ga          #+#    #+#             */
/*   Updated: 2025/05/19 21:07:00 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}
/*
int	main(void)
{
	ft_putstr_fd("son las nueve", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("el cielo esta cute", 2);
	return (0);
}*/
