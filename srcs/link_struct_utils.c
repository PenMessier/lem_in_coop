/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:57:55 by Elena             #+#    #+#             */
/*   Updated: 2020/03/12 13:52:56 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			add_link(t_link **links, t_room *start, t_room *end)
{
	t_link	*new;
	t_link	*curr;

	if (!(new = (t_link *)malloc(sizeof(*new))))
		return (0);
	new->start = end->stat == 2 ? end : start;
	new->end = end->stat == 2 ? start : end;
	new->next = NULL;
	if (!*links)
	{
		*links = new;
		return (1);
	}
	curr = *links;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (1);
}

void		swap_rooms(t_link *link)
{
	t_room	*tmp;

	tmp = link->start;
	link->start = link->end;
	link->end = tmp;
}
