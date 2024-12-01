/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:54:24 by ezekaj            #+#    #+#             */
/*   Updated: 2024/11/30 16:18:07 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_lists
{
	char			*str_buf;
	struct slist	*next;
}	t_list;

t_list	*find_last_node(t_list *list);

int		found_nl(t_list *list);
int		len_to_nl(t_list *list);

char	*get_next_line_h(int fd);
char	*get_line(t_list *list);

void	str_cpy(t_list *list, char *str);
void	create_list(t_list **list, int fd);
void	*ft_calloc(size_t count, size_t size);
void	append(t_list **list, char *buffer);
void	polish_list(t_list **list);
void	deallocate_list(t_list **list, t_list *clean_node, char *buffer);

#endif 