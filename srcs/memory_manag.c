/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:12:45 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 20:44:55 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	free_rooms(t_room *rooms)
{
	t_room	*curr;

	if (!rooms)
		return ;
	while (rooms)
	{
		if (rooms->links)
		{
			free_list_line(rooms->links);
		}
		if (rooms->name)
			free(rooms->name);
		curr = rooms->next;
		free(rooms);
		rooms = curr;
	}
}

static void	free_links(t_link *links)
{
	t_link	*curr;

	if (!links)
		return ;
	while (links)
	{
		curr = links->next;
		free(links);
		links = curr;
	}
}

void		free_struct(t_map *map)
{
	if (map)
	{
		free_list(&map->list);
		free_rooms(map->rooms);
		free_links(map->links);
	}
}
