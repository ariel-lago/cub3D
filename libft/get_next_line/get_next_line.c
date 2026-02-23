/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:56:54 by alago-ga          #+#    #+#             */
/*   Updated: 2025/08/11 16:32:18 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_find_line(t_gnl_list	*lstline)
{
	size_t	i;

	while (lstline)
	{
		i = 0;
		while (lstline->content && lstline->content[i])
		{
			if (lstline->content[i++] == '\n')
				return (1);
		}
		lstline = lstline->next;
	}
	return (0);
}

static t_gnl_list	*new_node_fd(int fd, int *err)
{
	t_gnl_list	*piece;
	ssize_t		bytes_read;

	piece = malloc(sizeof(t_gnl_list));
	if (!piece)
		return (NULL);
	piece->next = NULL;
	piece->content = malloc(BUFFER_SIZE + 1);
	if (!piece->content)
	{
		free(piece);
		return (NULL);
	}
	bytes_read = read(fd, piece->content, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (bytes_read < 0)
			*err = -1;
		free(piece->content);
		free(piece);
		return (NULL);
	}
	piece->content[bytes_read] = '\0';
	return (piece);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lstline = NULL;
	t_gnl_list			*piece;
	char				*line;
	int					err;

	err = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_find_line(lstline))
	{
		piece = new_node_fd(fd, &err);
		if (!piece)
			break ;
		ft_lst_add_back(&lstline, piece);
	}
	if (err == -1 || !lstline || ft_line_len(lstline) == 0)
	{
		ft_clean_sent_line(&lstline);
		return (NULL);
	}
	line = ft_lst_to_str(lstline, ft_line_len(lstline));
	ft_clean_sent_line(&lstline);
	return (line);
}
