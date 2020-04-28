/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:04:34 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 16:40:46 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			list_push(t_list **head, void *data, t_map *map)
{
	t_list		*item;

	if (!(item = (t_list *)malloc(sizeof(t_list))))
		put_error(map, ALLOCERR);
	item->data = data;
	item->next = *head;
	*head = item;
}

void			*list_pop(t_list **head)
{
	t_list		*item;
	void		*data;

	item = *head;
	*head = item->next;
	data = item->data;
	free(item);
	return (data);
}
