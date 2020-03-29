/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 19:08:47 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:23:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int n, fd[2];
    pid_t pid;
    char line[100];

    if (pipe(fd) < 0) {
        printf("pipe error \n");
        return(-1);
        /* err_sys("pipe error"); */
    }

    if ( (pid = fork()) < 0) {
        printf("fork error \n");
        return(-2);
        /* err_sys("fork error"); */

    } else if (pid > 0) { /* parent */

        close(fd[0]);
        write(fd[1], "Hello world\n", 12);

    } else { /* child */
        close(fd[1]);
        n = read(fd[0], line, sizeof(line));
        write(1, line, n);
    }

    return(0);
}
