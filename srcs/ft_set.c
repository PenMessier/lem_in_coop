/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:08:14 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:47:48 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

t_set		*set_new(t_map *map)
{
	t_set	*set;

	if (!(set = (t_set *)malloc(sizeof(t_set))))
		put_error(map, ALLOCERR);
	set->elements = NULL;
	return (set);
}

t_room		*set_pop_min(t_set *set)
{
	t_list	**addr;
	t_list	**addr_min;
	int		min_distance;

	if (set->elements == NULL)
		return (NULL);
	addr = &set->elements;
	addr_min = addr;
	min_distance = ((t_room *)(*addr)->data)->level;
	while (*addr != NULL)
	{
		if (((t_room *)(*addr)->data)->level < min_distance)
		{
			addr_min = addr;
			min_distance = ((t_room *)(*addr)->data)->level;
		}
		addr = &(*addr)->next;
	}
	return (list_pop(addr_min));
}

void		set_push(t_set *set, t_room *room, t_map *map)
{
	t_list	*element;

	element = set->elements;
	while (element != NULL)
	{
		if (element->data == room)
			return ;
		element = element->next;
	}
	list_push(&set->elements, room, map);
}

void		set_destroy(t_set *set)
{
	while (set->elements != NULL)
		(void)list_pop(&set->elements);
	free(set);
}
