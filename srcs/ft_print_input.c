/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:03:09 by Elena             #+#    #+#             */
/*   Updated: 2020/03/12 13:43:54 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	print_rooms(t_room *p_room)
{
	while (p_room)
	{
		if (p_room->stat == 2)
			write(1, "##start\n", 8);
		else if (p_room->stat == 3)
			write(1, "##end\n", 6);
		ft_putstr(p_room->name);
		write(1, " ", 1);
		ft_putnbr(p_room->x);
		write(1, " ", 1);
		ft_putnbr(p_room->y);
		write(1, "\n", 1);
		p_room = p_room->next;
	}
}

void		ft_print_input(t_map map)
{
	t_room	*p_room;
	t_link	*p_link;

	p_room = map.rooms;
	p_link = map.links;
	ft_putnbr(map.ant_count);
	write(1, "\n", 1);
	print_rooms(p_room);
	while (p_link)
	{
		ft_putstr(p_link->start->name);
		write(1, "-", 1);
		ft_putstr(p_link->end->name);
		write(1, "\n", 1);
		p_link = p_link->next;
	}
	write(1, "\n", 1);
}
