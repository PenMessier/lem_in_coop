/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:01:32 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:49:40 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	ft_fill_one(t_room *room, t_map *map)
{
	t_link		*link;

	link = map->links;
	room->links = NULL;
	while (link != NULL)
	{
		if (link->start == room && link->end != room)
			line_push(room, link->end, 1, map);
		if (link->end == room && link->start != room)
			line_push(room, link->start, 1, map);
		link = link->next;
	}
	room->parent = NULL;
	room->pred = NULL;
	room->succ = NULL;
	room->best_succ = NULL;
}

static void	ft_fill_list(t_map *map)
{
	t_room		*curr;

	curr = map->rooms;
	while (curr)
	{
		list_push(&map->list, curr, map);
		curr = curr->next;
	}
}

void		ft_refill_map(t_map *lemin)
{
	t_room	*tmp;

	tmp = lemin->rooms;
	lemin->list = NULL;
	ft_fill_list(lemin);
	while (tmp != NULL)
	{
		ft_fill_one(tmp, lemin);
		tmp->level = INT_MAX;
		tmp = tmp->next;
	}
}

static int	ft_connects(t_room *room)
{
	int			nom;
	t_list		*tmp;

	nom = 0;
	tmp = (t_list*)room->links;
	while (tmp != NULL)
	{
		nom++;
		tmp = tmp->next;
	}
	return (nom);
}

int			ft_max_link(t_map *lemin)
{
	int		start;
	int		end;

	start = ft_connects(lemin->start);
	end = ft_connects(lemin->end);
	if (start < end)
		return (start);
	else
		return (end);
}
