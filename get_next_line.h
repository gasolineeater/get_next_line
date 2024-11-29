/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezekaj <ezekaj@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:54:24 by ezekaj            #+#    #+#             */
/*   Updated: 2024/11/29 17:41:30 by ezekaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <errno.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <wchar.h>
# include <fcntl.h>

char *get_next_line_h(int fd);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);

void	*ft_calloc(size_t count, size_t size);

#endif 