/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:05:31 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/12/02 17:01:23 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	char *stash;
	char	buffer[BUFFER_SIZE + 1];
	int	read_byte;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if (stash == NULL)
	{
		stash = malloc(1);
		if (stash == NULL)
			return NULL;
		stash[0] = '\0';
	}
	while (read_byte = read(fd,buffer,BUFFER_SIZE) > 0)
	{
		buffer[read_byte] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash,buffer);
		free(tmp);
		if (ft_strchr(stash,'\n'));
			break;
	}
	/*line = extract_line(stash);
	stash = clean_stash(stash);
	return line;*/
	return stash;
}
