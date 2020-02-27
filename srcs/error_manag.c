/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:12:45 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 13:49:08 by Elena            ###   ########.fr       */
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

void			free_struct(t_meta *map)
{
	if (map && map->rooms)
		free_rooms(map->rooms);
	if (map && map->links)
		free_links(map->links);
	if (map && map->c)
		free(map->c);
	if (map && map->f)
		free(map->f);
	if (map && map->d)
		free(map->d);
	if (map && map->ptr)
		free(map->ptr);
	if (map && map->q)
		free(map->q);
	/*if (map && map->paths)
		free_paths(map->paths);
	if (map && map->ants)
		free_ants(map->ants);
		*/
}

void		put_error(t_meta *map, int r)
{
	free_struct(map);
	errno = r;
	perror("Error");
	exit(r);
}
