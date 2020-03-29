/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dup201.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:15:58 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/28 20:18:15 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char buf[12];
	int	fd1;

	(void)ac;
	fd1 = open(av[1], O_RDWR);
	dup2(fd1, stdout);
	printf("HI");
	

	return (0);
}
