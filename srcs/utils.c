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

void	error(char *message)
{
	perror(message);
	exit (1);
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
