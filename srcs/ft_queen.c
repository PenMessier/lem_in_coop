/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:20:30 by gerenfor          #+#    #+#             */
/*   Updated: 2020/04/05 11:27:28 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		ft_act(t_way *cool, t_map *map, int *ant, int *action)
{
	int		*rs;
	int		*rt;
	int		*as;
	int		*at;

	rt = &cool->roomno;
	rs = &((cool - 1)->roomno);
	at = &(cool->ant);
	as = &((cool - 1)->ant);
	if ((*rt == map->start->i || *rt < 0) && *as < 0 && *ant <= map->ant_count)
	{
		*at = *ant;
		*ant = *ant + 1;
		*action < 1 ? (*action = 1) : 0;
	}
	else if (*as >= 0)
		print_action(cool, action);
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
				ft_act(cool + max * j + i, map, &ant, &action);
		}
		j = 0;
		while (j < flow && ant <= map->ant_count)
			ft_rerot((cool + max * j), &ant, &j, &action);
		action > 2 ? write(1, "\n", 1) : 0;
	}
}
