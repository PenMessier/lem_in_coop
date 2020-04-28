/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:14:32 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 20:56:08 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

t_room		*create_new_room(int x, int y, int li, char *name)
{
	t_room	*new;

	if (!(new = (t_room *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = ft_strnew((size_t)li)))
		return (NULL);
	ft_memcpy(new->name, name, (size_t)li);
	new->x = x;
	new->y = y;
	new->stat = 0;
	new->level = -1;
	new->ant = 0;
	new->next = NULL;
	new->parent = NULL;
	new->pred = NULL;
	new->succ = NULL;
	new->best_succ = NULL;
	new->links = NULL;
	return (new);
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

static int	check_duplicate(char *existed, t_room *new)
{
	if (!ft_strcmp(existed, new->name))
	{
		free(new->name);
		free(new);
		return (0);
	}
	return (1);
}

static void	write_data(t_room *new, t_map *map, int *nl)
{
	map->start = *nl == 0 ? new : map->start;
	map->end = *nl == 1 ? new : map->end;
	new->stat = *nl == 0 ? 2 : 3;
	new->level = *nl == 0 ? 0 : new->level;
}

int			add_room(t_room *new, t_map *map, int *nl)
{
	t_room	*curr;

	if (!new)
		return (-5);
	if (*nl == 0 || *nl == 1)
		write_data(new, map, nl);
	*nl = 3;
	if (!(curr = map->rooms))
	{
		map->rooms = new;
		return (1);
	}
	while (curr->next)
	{
		if (!check_duplicate(curr->name, new))
			return (-8);
		curr = curr->next;
	}
	if (!check_duplicate(curr->name, new))
		return (-8);
	curr->next = new;
	return (1);
}
