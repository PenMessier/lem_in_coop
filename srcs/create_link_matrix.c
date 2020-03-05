/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:30 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:13:27 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void 		create_link_matrix(t_map *map)
{
	int		i;
	int		j;
	t_link	*curr;

	i = 0;
	curr = map->links;
	map->all->n = map->room_count;
	map->all->s = map->start->i;
	map->all->t = map->end->i;
	map->all->c = (int *)malloc(map->all->n * map->all->n * sizeof(int));
	map->all->f = (int *)malloc(map->all->n * map->all->n * sizeof(int));
	//all->d = (int *)malloc(all->room_count * sizeof(int));
	//all->q = (int *)malloc(all->room_count * sizeof(int));
	//all->ptr = (int *)malloc(all->room_count * sizeof(int));
	while (i < map->all->n * map->all->n)
	{
		map->all->c[i] = 0;
		map->all->f[i] = 0;
		i++;
	}
	while (curr)
	{
		if (curr->start->level != curr->end->level)
		{
			i = curr->start->i;
			j = curr->end->i;
			map->all->c[i * map->all->n + j] = 1;
			map->all->c[j * map->all->n + i] = 1;
		}
		curr = curr->next;
	}
}
