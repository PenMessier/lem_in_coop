/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:23:59 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 11:24:44 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_becool(t_way *cool, int *wae, t_map *map)
{
	while (cool->ant != -2)
		cool++;
	while (*wae != map->all->t)
		wae++;
	while (*wae != map->all->s)
	{
		cool->roomno = *wae;
		cool->room = get_room_name(map, cool->roomno);
		cool--;
		wae--;
	}
	cool->roomno = *wae;
	cool->room = get_room_name(map, cool->roomno);
}

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
