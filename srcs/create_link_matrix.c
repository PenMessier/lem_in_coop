/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:30 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 12:09:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			create_link_matrix(t_map *map)
{
	int		i;
	int		j;
	t_link	*curr;

	curr = map->links;
	map->all->n = map->room_count;
	map->all->s = map->start->i;
	map->all->t = map->end->i;
	if (!(map->all->c = (int *)malloc(map->all->n * map->all->n * sizeof(int)))
	|| !(map->all->f = (int *)malloc(map->all->n * map->all->n * sizeof(int))))
		return (0);
	ft_memset(map->all->c, 0, map->all->n * map->all->n * sizeof(int));
	ft_memset(map->all->f, 0, map->all->n * map->all->n * sizeof(int));
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
	return (1);
}
