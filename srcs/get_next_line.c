/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:03:56 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/24 11:01:57 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (i <= BUFFER_SIZE && fd < FOPEN_MAX && fd >= 0)
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_create(line, buffer);
		cleanbuffer(buffer, &flag);
	}
	return (line);
}

/*int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	
	char *line;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break ;
		free(line);
	}
	return (0);
}*/
