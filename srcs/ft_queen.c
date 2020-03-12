/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:20:30 by gerenfor          #+#    #+#             */
/*   Updated: 2020/03/12 09:12:29 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

char			*ft_runo(t_map *map, int no)
{
	t_room	*tmp;
	
	tmp = map->rooms;
	while (tmp->i != no)
		tmp = tmp->next;
	return (tmp->name);
}

void	ft_becool(t_way *cool, int *wae, t_map *map)
{
	while(cool->ant != -2)
		cool++;
	while(*wae != map->all->t)
		wae++;
	while(*wae != map->all->s)
	{
		cool->roomno = *wae;
		cool->room = ft_runo(map, cool->roomno);
		cool--;
		wae--;
	}
	cool->roomno = *wae;
	cool->room = ft_runo(map, cool->roomno);
}

void	ft_full(t_way *cool, int max, int row)
{
	int i;

	i = 0;
	while (i < max * row)
	{
		cool[i].room = NULL;
		cool[i].roomno = -1;
		cool[i].ant = -1;
		if ((i + 1) % max == 0)
			cool[i].ant = -2;
		i++;
	}
}

int		ft_react(t_way *cool)
{
	int	*rs;
	int	*rt;
	int	*as;
	int	*at;

	rt = &cool->roomno;
	rs = &((cool - 1)->roomno);
	at = &(cool->ant);
	as = &((cool - 1)->ant);
	if (*rs >= 0 && *rt >= 0)
	{
		write(1, "L", 1);
		ft_putnbr(*as);
		write(1, "-", 1);
		write(1, cool->room, ft_strlen(cool->room));
		write(1, " ", 1);
	}
	*at = *as;
	*as = -1;
	return (2);
}

int		ft_act(t_way *cool, t_map *map, int *ant)
{
	int	action;
	int	*rs;
	int	*rt;
	int	*as;
	int	*at;

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
		action = ft_react(cool);
	return (action);
}

void	ft_rerot(t_way *cool, int *ant, int *j, int *action)
{
	cool->ant = *ant;
	*ant = *ant + 1;
	*j = *j + 1;
	if (*action < 1)
		*action = 1;
}

void	ft_rotate(int max, int flow, t_way *cool, t_map *map)
{
	int i;
	int j;
	int ant;
	int action;
	int act;

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
				if ((act = ft_act(cool + max * j + i, map, &ant)) && action < act)
					action = act;
		}
		j = 0;
		while (j < flow && ant <= map->ant_count)
			ft_rerot((cool + max * j), &ant, &j, &action);
		if (action == 2)
			write(1, "\n", 1);
	}
}

void		ft_queen(int max, int flow, int	*wae, t_map *map)
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
