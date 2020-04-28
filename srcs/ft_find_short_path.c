/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_short_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:21:40 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:43:19 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	update_neighbors(t_room *start, t_set *set, t_map *map)
{
	t_list		*links;
	t_line		*l;
	t_room		*dst;
	int			new_distance;

	links = start->links;
	while (links != NULL)
	{
		l = links->data;
		dst = l->dst;
		new_distance = start->level + l->weight;
		if (new_distance < dst->level)
		{
			dst->level = new_distance;
			dst->parent = start;
			set_push(set, dst, map);
		}
		links = links->next;
	}
}

int			find_shortest_path(t_room *start, t_room *end, t_map *map)
{
	t_set	*set;

	set = set_new(map);
	start->level = 0;
	while (start != NULL && start != end)
	{
		update_neighbors(start, set, map);
		start = set_pop_min(set);
	}
	set_destroy(set);
	return (start == end);
}
