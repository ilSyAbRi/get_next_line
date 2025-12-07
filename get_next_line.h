/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:30:14 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/12/07 11:59:55 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be greater than 0"
# endif

// main function
char	*get_next_line(int fd);

// helper function
size_t	ft_strlen(const char *s);
int		check_newline_or_null(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
