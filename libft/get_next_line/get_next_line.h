/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:22:58 by alago-ga          #+#    #+#             */
/*   Updated: 2025/08/11 16:30:20 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;

char		*get_next_line(int fd);
void		ft_lst_add_back(t_gnl_list **lst, t_gnl_list *node);
size_t		ft_line_len(t_gnl_list *lstline);
char		*ft_lst_to_str(t_gnl_list *lstline, size_t len);
void		ft_clean_sent_line(t_gnl_list **lstline);
t_gnl_list	*ft_rest_node(char *content);

#endif
