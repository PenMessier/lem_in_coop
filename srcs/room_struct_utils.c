/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:14:32 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 11:05:45 by Elena            ###   ########.fr       */
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
	new->ant = 0;
	new->next = NULL;
	return (new);
}

int			add_room(t_room *new, t_meta *map, int *nl)
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
	return NULL;
}

int		count_index_rooms(t_room **rooms)
{
	t_room	*curr;
	int			i;
	
	curr = *rooms;
	i = 0;
	while (curr)
	{
		curr->i = i;
		curr = curr->next;
		i++;
	}
	return (i);
}