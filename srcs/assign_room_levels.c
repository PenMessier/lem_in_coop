/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_room_levels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:59:05 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 12:57:56 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		check_end_level(t_map *map)
{
	t_room	*curr;
	int		end_level;

	curr = map->rooms;
	end_level = map->end->level;
	while (curr)
	{
		if (curr->stat != 3 && curr->level == end_level)
			map->end->level += 1;
		curr = curr->next;
	}
}

void		assign_level(t_map *map, int level)
{
	t_link	*cur_link;

	cur_link = map->links;
	while (cur_link)
	{
		if (cur_link->start->level == level && cur_link->end->level == -1)
			cur_link->end->level = level + 1;
		if (cur_link->end->level == level && cur_link->start->level == -1)
		{
			cur_link->start->level = level + 1;
			if (cur_link->end->stat != 3)
				swap_rooms(cur_link);
		}
		cur_link = cur_link->next;
	}
	if (map->end->level == -1)
		assign_level(map, level + 1);
}
