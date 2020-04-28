/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_index_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 11:58:07 by Elena             #+#    #+#             */
/*   Updated: 2020/04/05 12:20:34 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int				count_index_rooms(t_room *rooms)
{
	int		i;
	t_room	*start;
	t_room	*curr;

	curr = rooms;
	i = 0;
	while (curr)
	{
		if (curr->stat == 2)
			start = curr;
		curr->i = i++;
		curr = curr->next;
	}
	if (start->i != 0)
	{
		curr = rooms;
		while (curr && curr->i != 0)
			curr = curr->next;
		curr->i = start->i;
		start->i = 0;
	}
	return (i);
}
