/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:39:42 by ezekaj            #+#    #+#             */
/*   Updated: 2024/12/05 19:04:24 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list **list)
{
	t_list	*temp;
	int		i;	
	
	temp = *list;
	if (NULL == temp)
		return (0);
	while (temp)
	{
		i = 0;
		while (temp->str_buf[i])
		{
			if (temp->str_buf[i] == '\n')
				return (1);
			i++;
		}
		temp = temp->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	t_list	*last_node;
	if (NULL == list)
		return (NULL);
	last_node = list;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	ft_strcpy(t_list *list, char *str)
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

int	len_to_newline(t_list *list)
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
