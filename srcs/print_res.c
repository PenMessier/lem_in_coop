/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:03:09 by Elena             #+#    #+#             */
/*   Updated: 2020/02/26 16:12:29 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	print_input(t_meta map)
{
	t_room	*p_room;
	t_link	*p_link;

	p_room = map.rooms;
	p_link = map.links;
	printf("%d\n", map.ant_count);
	while (p_room)
	{
		if (p_room->stat == 2)
			printf("##start\n");
		else if (p_room->stat == 3)
			printf("##end\n");
		printf("%s %d %d\n", p_room->name, p_room->x,  p_room->y);
		p_room = p_room->next;
	}
	while (p_link)
	{
		printf("%s-%s\n", p_link->start->name, p_link->end->name);
		p_link = p_link->next;
	}
	printf("start %s\n", (map.start)->name);
	printf("end %s\n", (map.end)->name);
}
