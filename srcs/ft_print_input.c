/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:03:09 by Elena             #+#    #+#             */
/*   Updated: 2020/03/13 12:53:36 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	print_rooms(t_room *p_room)
{
	int			max_level;

	max_level = 0;
	while (p_room)
	{
		if (p_room->level > max_level)
			max_level = p_room->level;
		p_room = p_room->next;
	}
	printf("level %d\n", max_level);
}

void		ft_print_input(t_map map)
{
	t_room	*p_room;
	t_link	*p_link;
	int			i;

	i = 0;
	p_room = map.rooms;
	p_link = map.links;
	while (p_link)
	{
		i++;
		p_link = p_link->next;
	}
	// printf("links %d\n", i);
	printf("rooms %d\n", map.room_count);
	printf("level %d\n", map.end->level);
	print_rooms(p_room);
	write(1, "\n", 1);
}
