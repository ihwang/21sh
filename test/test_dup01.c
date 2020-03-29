/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dup01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:02:28 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 20:15:02 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char **argv)
{
	int fd1;
	int fd2;
	char buf[12];

	fd1 = open(argv[1], O_RDWR);
	fd2 = dup(fd1);

	(void)argc;
	bzero(buf, sizeof(buf));
	read(fd1, buf, sizeof(buf));
	printf("fd1 : %s\n", buf);
	close(fd1);
	bzero(buf, sizeof(buf));
	read(fd2, buf, 2);
	printf("fd2 : %s\n", buf);
	return (0);
}
