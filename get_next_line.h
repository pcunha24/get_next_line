/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:25:47 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/08 15:16:41 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
