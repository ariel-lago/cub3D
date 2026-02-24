/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:36:14 by alago-ga          #+#    #+#             */
/*   Updated: 2025/08/11 16:34:04 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lst_add_back(t_gnl_list **lst, t_gnl_list *node)
{
	t_gnl_list	*last;

	if (!lst || !node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = node;
}

size_t	ft_line_len(t_gnl_list *lstline)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (lstline)
	{
		i = 0;
		while (lstline->content[i])
		{
			len++;
			if (lstline->content[i] == '\n')
				return (len);
			i++;
		}
		lstline = lstline->next;
	}
	return (len);
}

char	*ft_lst_to_str(t_gnl_list *lstline, size_t len)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (lstline && len > 0)
	{
		j = 0;
		while (lstline->content[j] && len > 0)
		{
			line[i++] = lstline->content[j++];
			len--;
		}
		lstline = lstline->next;
	}
	line[i] = '\0';
	return (line);
}

void	ft_clean_sent_line(t_gnl_list **lstline)
{
	t_gnl_list	*current;
	t_gnl_list	*temp;
	t_gnl_list	*rest;
	size_t		i;

	i = 0;
	if (!*lstline)
		return ;
	current = *lstline;
	while (current->next)
	{
		temp = current;
		current = current->next;
		free(temp->content);
		free(temp);
	}
	while (current->content[i] && current->content[i] != '\n')
		i++;
	if (current->content[i] == '\n' && current->content[i + 1])
	{
		rest = ft_rest_node(&current->content[i + 1]);
		free(current->content);
		free(current);
		*lstline = rest;
	}
	else
	{
		free(current->content);
		free(current);
		*lstline = NULL;
	}
}

t_gnl_list	*ft_rest_node(char *content)
{
	t_gnl_list	*node;
	char		*rest;
	size_t		i;

	i = 0;
	while (content[i])
		i++;
	rest = malloc(i + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (*content)
		rest[i++] = *content++;
	rest[i] = '\0';
	node = malloc(sizeof(t_gnl_list));
	if (!node)
	{
		free(rest);
		return (NULL);
	}
	node->content = rest;
	node->next = NULL;
	return (node);
}
