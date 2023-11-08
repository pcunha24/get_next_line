/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:12:43 by pedalexa          #+#    #+#             */
/*   Updated: 2023/11/08 15:32:58 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*extract_line(char *bacia_buffer)
{
	int		i;
	int		n;
	char	*line;

	i = 0;
	n = 0;
	while (bacia_buffer[i] != '\n' && bacia_buffer[i] != '\0')
	{
		i++;
	}
	if (bacia_buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	while (n <= i)
	{
		line[n] = bacia_buffer[n];
		n++;
	}
	line[n] = '\0';
	return (line);
}
char	*obtain_remaining(char *bacia_buffer)
{
	bacia_buffer = ft_strchr(bacia_buffer, '\n');
	return (bacia_buffer);
}

char	*append_buffer(char *bacia_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(bacia_buffer, read_buffer);
	free(bacia_buffer);
	return (temp);
}
// Function that reads data from the file
char	*read_from_file(char *bacia_buffer, int fd)
{
	char		*balde_buffer;
	ssize_t		bytesread;

	balde_buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (balde_buffer == NULL)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, balde_buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(balde_buffer);
			return (NULL);
		}
		balde_buffer[bytesread] = '\0';
		bacia_buffer = append_buffer(bacia_buffer, balde_buffer);
		if (ft_strchr(bacia_buffer, '\n'))
			break;
	}
	free(balde_buffer);
	return (bacia_buffer);
}

char	*get_next_line(int fd)
{
	static char	*bacia_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0)
		return(NULL);
	if (!bacia_buffer)
		bacia_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(bacia_buffer, '\n'))
		bacia_buffer = read_from_file(bacia_buffer, fd);
	if (!bacia_buffer)
	{
		free(bacia_buffer);
		return (NULL);
	}
	line = extract_line(bacia_buffer);
	bacia_buffer = obtain_remaining(bacia_buffer);
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
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n",count, line);
		free(line);
	}
	close(fd);
	return (0);
}
