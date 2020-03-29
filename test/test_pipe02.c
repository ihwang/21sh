/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 19:41:07 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:43:57 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(void){
    char buffer[BUFSIZ];
    int fd[2];
    pipe(fd);
    pid_t pid;
    pid = fork();
    if(pid==0)
	{ //자식 프로세스의 경우//
        write(fd[1],"This letter is from child",BUFSIZ);
		sleep(1);
        read(fd[0],buffer,BUFSIZ);
        printf("Output of child process :: %s \n\n",buffer);
    }
    else
	{ //부모 프로세스의 경우//
        read(fd[0],buffer,BUFSIZ);
        printf("Output of parent process :: %s \n\n",buffer);
        write(fd[1],"This letter is from parent.",BUFSIZ);
    }
    exit(0);
}

