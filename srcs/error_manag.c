/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:12:45 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:47:37 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	free_rooms(t_room *rooms)
{
	t_room	*curr;

	while (rooms)
	{
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

	while (links)
	{
		curr = links->next;
		free(links);
		links = curr;
	}
}

/*static void	free_paths(t_path *paths)
{
	t_path	*curr;

	while (paths)
	{
		if (paths->rooms)
			free(paths->rooms);
		curr = paths->next;
		free(paths);
		paths = curr;
	}
}

static void	free_ants(t_ant *ants)
{
	t_ant	*curr;

	while (ants)
	{
		curr = ants->next;
		free(ants);
		ants = curr;
	}
}*/

void			free_meta(t_meta *all)
{
	if (all && all->c)
		free(all->c);
	if (all && all->f)
		free(all->f);
	if (all && all->d)
		free(all->d);
	if (all && all->ptr)
		free(all->ptr);
	if (all && all->q)
		free(all->q);
}

void			free_struct(t_map *map)
{
	if (map && map->rooms)
		free_rooms(map->rooms);
	if (map && map->links)
		free_links(map->links);
	if (map && map->all)
		free_meta(map->all);
}

void		put_error(t_map *map, int r)
{
	free_struct(map);
	errno = r;
	perror("Error");
	exit(r);
}
