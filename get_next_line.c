/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:12:43 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/20 15:55:30 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line (int fd)
{
    static char    buffer[BUFFER_SIZE + 1];
    char		*line;
    int         i;

    line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    {
        i = 0;
        //printf("buffer- %s\n", buffer);
        line = ft_strjoin(line, buffer);
        // printf("buffer- %s\n", buffer);
        // printf("line - %s\n", line);
        ft_bzero(buffer);
        while (line[i++])
        {
            if (line[i] == '\n')
                return (line);
        }
        
    }
	return (line);
    
}
int main (void)
{
	char	*filename = "file.txt";
	int	fd;
	char	*line;
	int	count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
    // line = get_next_line(fd);
    // printf("%s", line);
    free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n",count, line);
		free(line);
	}
	close(fd);
	return (0);
}
