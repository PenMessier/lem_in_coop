/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_room_levels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:59:05 by frenna            #+#    #+#             */
/*   Updated: 2020/03/16 19:36:18 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		check_end_level(t_map *map)
{
	t_room	*curr;

	curr = map->rooms;
	while (curr)
	{
		if (curr->stat != 3 && curr->level == map->end->level)
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
		}
		if ((cur_link->start->level > cur_link->end->level && cur_link->end->stat != 3)
			|| cur_link->start->stat == 3)
				swap_rooms(cur_link);
		cur_link = cur_link->next;
	}
	if (level < map->room_count)
		assign_level(map, level + 1);
}

int		find_dead_end(t_map *map, int	check_lvl)
{
	t_link	*curr;
	int			cur_lvl;

	curr = map->links;
	while (curr)
	{
		if (curr->start->level == check_lvl && curr->end->level == map->end->level)
			return (0);
		curr = curr->next;
	}
	cur_lvl = check_lvl;
	while ((cur_lvl = find_dead_end(map, cur_lvl - 1)) != 0)
		check_lvl = cur_lvl;
	return (check_lvl);
}
