/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 19:13:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/29 20:07:04 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

t_term				default_term(t_term *t)
{
	static t_term	old;

	if (t)
	{
		old = *t;
		return (0);
	}
	else
		return (old);
}

void				init_term(void)
{
	t_term			t;

	tcgetattr(0, &t);
	default_term(t);
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
}

int					parse_key(char tmp[], char **line)
{
	 if (tmp[0] == 27 && tmp[1] == 91 && tmp[2] == 'A')
		up_key();
	else if (tmp[0] == 27 && tmp[1] == 91 && tmp[2] == 'B')
		down_key();
	else if (tmp[0] == 27 && tmp[1] == 91 && tmp[2] == 'D')
		left_key();
	else if (tmp[0] == 27 && tmp[1] == 91 && tmp[2] == 'C')
		right_key();
	else if (tmp[0] == 127 && tmp[1] == '\0')
		bs_key();
	else if (tmp[0] == '\n' && tmp[1] == '\0')
		enter_key();
}

void				get_line(char **line)
{
	char	tmp[8];

	init_term();
	while (1)
	{
		ft_bzero(tmp, sizeof(tmp));
		read(0, tmp, sizeof(tmp));
		parse_key(tmp, line);
	}	


}
