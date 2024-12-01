/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:40:07 by ezekaj            #+#    #+#             */
/*   Updated: 2024/12/01 16:56:23 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = ft_calloc(1, BUFFER_SIZE + 1);
	clean_node = ft_calloc(1, sizeof(t_list));
	if (NULL == clean_node || NULL == buffer)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] != '\n' && last_node->str_buf[i] != '\0')
		i++;
	while (last_node->str_buf[i] != '\0')
	{
		buffer[j] = last_node->str_buf[i];
		++i;
		++j;
	}
	buffer[j] = '\0';
	clean_node->str_buf = buffer;
	clean_node->next = NULL;
	deallocate_list(list, clean_node, buffer);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_nl(list);
	next_str = ft_calloc(1, str_len + 1);
	if (!next_str)
		return (NULL);
	str_cpy(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = ft_calloc(1, sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_nl(*list))
	{
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
}
