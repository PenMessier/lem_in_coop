/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_more_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:30:59 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:12:08 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			adjust_parents(t_room *x)
{
	t_room	*p;
	t_line	*l;
	t_room	*r;

	while ((p = x->parent) != NULL)
	{
		l = p->links->data;
		if (l->weight == 0)
		{
			r = l->dst;
			if (r != x)
				x->parent = r;
			r->parent = p->parent;
		}
		x = x->parent;
	}
}

void			tidy_up(t_list *rooms)
{
	t_room	*room;

	while (rooms != NULL)
	{
		room = rooms->data;
		room->level = INT_MAX;
		room->parent = NULL;
		rooms = rooms->next;
	}
}

int				find_more_paths(t_map *map)
{
	int			found;

	modify_graph(map);
	found = find_shortest_path(map->start, map->end, map);
	adjust_parents(map->end);
	restore_graph(map);
	combine_paths(map->start, map->end);
	tidy_up(map->list);
	return (found);
}
