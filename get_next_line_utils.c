/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:25:05 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/20 15:53:23 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *ptr)
{
	size_t	i;
    size_t  h;

	i = 0;
    h = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		ptr[i] = 0;
		i++;
	}
    if (ptr[i] == '\n')
    {
        ptr[i] = 0;
        i++;
    }
    while (ptr[i])
    {
        ptr[h] = ptr[i];
        i++;
        h++;
    }
    while (ptr[h])
    {
        ptr[h] = 0;
        h++;
    }
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

    if (!str)
        return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
    if (str[i] == '\n')
    {
      i++;  
    }
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		h;
	char	*str;

	i = 0;
	h = 0;
    // printf("%s\n", s1);
    // printf("%s\n", s2);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
    if (s1)
    {
	    while (s1[i] && s1)
	    {
		    str[i] = s1[i];
		    i++;
	    }
    }
	while (s2[h] != '\0' && s2[h] != '\n')
	{
		str[i] = s2[h];
		i++;
		h++;
	}
    if (s2[h] == '\n')
        str[i++] = s2[h];
	str[i] = '\0';
    // printf("%s\n", str);
    free(s1);
	return (str);
}
