/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasolineeater <gasolineeater@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:36:18 by ezekaj            #+#    #+#             */
/*   Updated: 2025/01/30 15:11:07 by gasolineeat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_polish(t_list **list)
{
	t_list	*temp;

	while ((*list))
	{
		temp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = temp;
	}
}

char	*ft_get_line(t_list	*list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (0);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (0);
	ft_strcpy(list, next_str);
	return (next_str);
}

void	ft_append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
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

	while (!found_newline(list))
	{
		buffer = malloc(sizeof(char *) + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, 1);
		if (char_read == 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = ft_get_line(list);
	ft_polish(&list);
	return (next_line);
}

// int main(void)   
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	close(fd);
// 	return (0);
// }
