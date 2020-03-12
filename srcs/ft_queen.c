/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:20:30 by gerenfor          #+#    #+#             */
/*   Updated: 2020/03/12 11:52:51 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			ft_act(t_way *cool, t_map *map, int *ant)
{
	int		action;
	int		*rs;
	int		*rt;
	int		*as;
	int		*at;

	rt = &cool->roomno;
	rs = &((cool - 1)->roomno);
	at = &(cool->ant);
	as = &((cool - 1)->ant);
	action = 0;
	if ((*rt == map->all->s || *rt < 0) && *as < 0 && *ant <= map->ant_count)
	{
		*at = *ant;
		*ant = *ant + 1;
		action = 1;
	}
	else if (*as >= 0)
		action = print_action(cool);
	return (action);
}

void		ft_rerot(t_way *cool, int *ant, int *j, int *action)
{
	cool->ant = *ant;
	*ant = *ant + 1;
	*j = *j + 1;
	if (*action < 1)
		*action = 1;
}

void		ft_rotate(int max, int flow, t_way *cool, t_map *map)
{
	int		i;
	int		j;
	int		ant;
	int		action;
	int		act;

	action = 1;
	ant = 1;
	while (action != 0 || ant <= map->ant_count)
	{
		action = 0;
		i = max;
		while (--i > 0)
		{
			j = -1;
			while (++j < flow)
				if ((act = ft_act(cool + max * j + i, map, &ant))
				&& action < act)
					action = act;
		}
		j = 0;
		while (j < flow && ant <= map->ant_count)
			ft_rerot((cool + max * j), &ant, &j, &action);
		action == 2 ? write(1, "\n", 1) : 0;
	}
}

void		ft_queen(int max, int flow, int *wae, t_map *map)
{
	t_way	cool[(max + 1) * flow];
	int		i;

	ft_full(cool, max + 1, flow);
	i = 0;
	while (i < flow)
	{
		ft_becool(cool + ((max + 1) * i), wae + map->all->n * i, map);
		i++;
	}
	ft_rotate(max + 1, flow, cool, map);
}
