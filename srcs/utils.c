/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:43:23 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 17:46:01 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
Writes "Error\n" to stderr
If p flag is activated it sends the message through perror
Otherwise it simply sends the message to strderr
*/
void	error(char *message, int p)
{
	write(2, "Error\n", 6);
    if (p)
        perror(message);
    else
        ft_putendl_fd(message, 2);
}

void free_array(char **arr)
{
    int i;

    if (!arr)
        return;
    
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
