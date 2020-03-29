/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:48:44 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/29 19:52:14 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	struct termios t;
	char	buf[10];

	tcgetattr(0, &t);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
	while (1)
	{
	read(0, buf, sizeof(buf));
	}
	return (0);
}
