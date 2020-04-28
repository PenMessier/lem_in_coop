/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:27:17 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 20:54:42 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			free_list(t_list **list)
{
	t_list	*tmp;

	if (!*list)
	{
		return ;
	}
	while ((*list)->next != NULL)
	{
		tmp = *list;
		*list = tmp->next;
		tmp->next = NULL;
		tmp->data = NULL;
		free(tmp);
		tmp = NULL;
	}
	(*list)->next = NULL;
	(*list)->data = NULL;
	free(*list);
	*list = NULL;
}

void			free_list_line(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (list)
	{
		if (list->data)
			free(list->data);
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
