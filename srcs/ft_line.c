/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:35:36 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 17:35:37 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		line_push(t_room *src, t_room *dst, int weight, t_map *map)
{
	t_line	*l;

	if (!(l = (t_line *)malloc(sizeof(t_line))))
		put_error(map, ALLOCERR);
	l->dst = dst;
	l->weight = weight;
	list_push(&src->links, l, map);
}

t_room		*line_pop(t_room *src)
{
	t_room	*dst;

	dst = ((t_line *)src->links->data)->dst;
	free(list_pop(&src->links));
	return (dst);
}

void		line_delete(t_room *src, t_room *dst)
{
	t_list	**addr;

	addr = &src->links;
	while (((t_line *)(*addr)->data)->dst != dst)
		addr = &(*addr)->next;
	free(list_pop(addr));
}

t_line		*line_find(t_room const *src, t_room const *dst)
{
	t_list	*links;

	links = src->links;
	while (links != NULL)
	{
		if (((t_line *)links->data)->dst == dst)
			return (links->data);
		links = links->next;
	}
	return (NULL);
}
