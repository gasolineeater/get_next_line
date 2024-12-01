/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:37:57 by ezekaj            #+#    #+#             */
/*   Updated: 2024/12/01 16:57:17 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	while (mem[i] != '\0')
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

int	found_nl(t_list *list)
{
	if (NULL == list)
		return (0);
	while (list)
	{
		while (*list->str_buf)
		{
			if (*list->str_buf == '\n')
				return (1);
			++list->str_buf;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	str_cpy(t_list *list, char *str)
{
	int	i;
	int	j;

	if (NULL == list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j] = '\0';
				return ;
			}
			str[j] = list->str_buf[i];
			++i;
			++j;
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	len_to_nl(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	deallocate_list(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*temp;

	if (NULL == list || NULL == clean_node || NULL == buffer)
		return ;
	temp = *list;
	while (temp->next != clean_node)
		temp = temp->next;
	temp->next = NULL;
	free(clean_node->str_buf);
	free(clean_node);
	free(buffer);
}
