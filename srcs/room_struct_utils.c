/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:14:32 by frenna            #+#    #+#             */
/*   Updated: 2020/03/03 19:45:09 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

t_room		*create_new_room(int x, int y, char *name, int li)
{
	t_room	*new;

	if (!(new = (t_room *)malloc(sizeof(*new))))
		return NULL;
	if (!(new->name = ft_strnew((size_t)li)))
		return NULL;
	ft_memcpy(new->name, name, (size_t)li);
	new->x = x;
	new->y = y;
	new->stat = 0;
	new->level = -1;
	new->ant = 0;
	new->next = NULL;
	return (new);
}

int				add_room(t_room *new, t_meta *map, int *nl)
{
	t_room	*curr;

	curr = map->rooms;
	if (!new)
		return (0);
	if (*nl == 0 || *nl == 1)
	{
		map->start = *nl == 0 ? new : map->start;
		map->end = *nl == 1 ? new : map->end;
		new->stat = *nl == 0 ? 2 : 3;
		new->level = *nl == 0 ? 0 : new->level;
	}
	*nl = 3;
	if (!map->rooms)
	{
		map->rooms = new;
		return (1);
	}
	while (curr->next)
	{
		if (!ft_strcmp(curr->name, new->name))
			return (0);
		curr = curr->next;
	}
	curr->next = new;
	return (1);
}

t_room		*find_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, name))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

void			assign_level(t_meta *map, int level)
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
			swap_rooms(cur_link);
		}
		cur_link = cur_link->next;
	}
	if (map->end->level == -1)
		assign_level(map, level + 1);
}

int		count_index_rooms(t_room *rooms)
{
	t_room	*curr;
	int			i;

	curr = rooms;
	i = 0;
	while (curr)
	{
		curr->i = i;
		curr = curr->next;
		i++;
	}
	return (i);
}