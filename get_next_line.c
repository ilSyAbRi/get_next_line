/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:05:31 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/12/05 08:42:24 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (line == NULL)
		return (NULL);
	while (j < i + (stash[i] == '\n'))
	{
		line[j] = stash[j];
		j++;
	}
	line[i + (stash[i] == '\n')] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (new_stash == NULL)
		return (NULL);
	ft_strlcpy(new_stash, stash + i + 1, ft_strlen(stash + i) + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_byte = read(fd, buffer, BUFFER_SIZE);
	while (read_byte > 0)
	{
		buffer[read_byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
		read_byte = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (read_byte < 0 || stash == NULL)
		return (free(stash), NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
