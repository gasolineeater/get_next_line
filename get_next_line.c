/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:40:07 by ezekaj            #+#    #+#             */
/*   Updated: 2024/11/29 17:43:47 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		char_read;
	int		buffer_size;

	buffer_size = 10;
	fd = open("file.txt", O_RDONLY);
	buffer = ft_calloc(1, buffer_size);
	if (!buffer)
		return (NULL);
	char_read = read(fd, buffer, buffer_size);
	while (char_read)
	{
		buffer[char_read] = '\0';
		printf("%s \n", buffer);
	}
}
