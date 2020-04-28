/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restore_graph.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:16:59 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:14:08 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void		restore_path(t_room *out, t_map *map)
{
	t_room		*in;
	t_room		*pred_out;

	line_delete(map->end, out);
	while (out != map->start)
	{
		in = line_pop(out);
		pred_out = line_pop(in);
		in->links = out->links;
		free(out);
		line_push(in, in->succ, LINK_POSITIVE, map);
		line_push(in->succ, in, LINK_POSITIVE, map);
		out = pred_out;
	}
	line_push(map->start, in, LINK_POSITIVE, map);
	line_push(in, map->start, LINK_POSITIVE, map);
}

void			restore_graph(t_map *map)
{
	t_list		*links;
	t_line		*l;

	links = map->end->links;
	while (links != NULL)
	{
		l = links->data;
		links = links->next;
		if (l->weight == LINK_NEGATIVE)
			restore_path(l->dst, map);
	}
}
