/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:34:31 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/12/03 18:38:45 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
int main(void)
{
	int	fd = open("test.txt",O_RDONLY);

	printf("%d\n",fd);
	printf("%s\n",get_next_line(fd));
    return 0;
}
