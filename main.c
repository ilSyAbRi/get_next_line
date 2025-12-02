/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:34:31 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/30 18:46:00 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    // هنا نستدعي get_next_line فقط لاختبار read + stash
    char *line = get_next_line(fd);

    // اطبع ما يوجد في stash بعد أول read
    printf("First call: %s\n", line);

    // استدعاء ثاني
    line = get_next_line(fd);
    printf("Second call: %s\n", line);

    close(fd);
    return 0;
}
