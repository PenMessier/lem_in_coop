/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_graph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:04:07 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:03:51 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

t_room			*room_new(t_map *map)
{
	t_room		*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		put_error(map, ALLOCERR);
	room->i = -1;
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->links = NULL;
	room->stat = -5;
	room->ant = -5;
	room->level = INT_MAX;
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	room->best_succ = NULL;
	return (room);
}

static void		modify_path(t_room *in, t_map *map)
{
	t_room		*out;

	line_delete(map->end, in);
	while (in != map->start)
	{
		line_delete(in, in->succ);
		line_delete(in, in->pred);
		out = room_new(map);
		out->links = in->links;
		in->links = NULL;
		line_push(in->succ, out, LINK_NEGATIVE, map);
		line_push(out, in, LINK_ZERO, map);
		if (in->pred == map->start)
		{
			line_delete(map->start, in);
			line_push(in, map->start, LINK_NEGATIVE, map);
		}
		in = in->pred;
	}
}

void			modify_graph(t_map *map)
{
	t_list		*links;
	t_line		*l;

	links = map->end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->dst->succ == map->end)
			modify_path(l->dst, map);
	}
}
