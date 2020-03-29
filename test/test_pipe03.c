/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe03.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 19:48:20 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 19:48:37 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(void){
    char buffer[BUFSIZ];
    int fd[2];
    if(pipe(fd)==-1)
	{
        perror("pipe error..\n");
        exit(0);
    }
    pid_t pid;
    pid = fork();
    if(pid == -1)
	{
        perror("fork error..\n");
        exit(0);
    }
    else if(pid==0)
	{ //자식 프로세스의 경우//
        write(fd[1],"This letter is from child",BUFSIZ);
        sleep(1); //레이스 컨디션 문제 발생. 부모보다 자식이 먼저 fd에 있는 자료를
                      //가져갈 수 있으므로, 좀 쉬어준다. (fd에 있는 자료는 먼저 가져가는 사람이 임자.)
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
