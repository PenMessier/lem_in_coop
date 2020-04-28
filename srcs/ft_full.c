/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:59 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 11:19:28 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_full(t_way *cool, int max, int row)
{
	int i;

	i = 0;
	while (i < max * row)
	{
		cool[i].room = NULL;
		cool[i].roomno = -1;
		cool[i].ant = -1;
		if ((i + 1) % max == 0)
			cool[i].ant = -2;
		i++;
	}
}
