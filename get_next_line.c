/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:05:31 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/30 18:53:32 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	char *stash = NULL;
	char buffer[BUFFER_SIZE + 1];
	int	bytes_read;
	char*	tmp;
	while ((bytes_read = read (fd,buffer,BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash,buffer);
		free(tmp);
		if (ft_strchr(stash,'\n'))
			break;
	}

	/*line = extract_line(stash);
	stash = clean_stash(stash);
	return line;*/
	return stash;
}
