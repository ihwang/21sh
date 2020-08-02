/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 08:30:42 by dthan             #+#    #+#             */
/*   Updated: 2020/08/02 15:59:09 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** and_or	:                         pipeline
**			| and_or AND_IF linebreak pipeline    //not
**        	| and_or OR_IF  linebreak pipeline    //not
*/

t_astnode	*and_or(t_token **token)
{
	return (pipeline(token));
}
