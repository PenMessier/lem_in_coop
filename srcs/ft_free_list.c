/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:27:17 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 11:28:47 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			free_list(t_list **list)
{
	t_list	*tmp;

	if (!(*list))
		return ;
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

void			free_list_line(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		while ((*list)->next != NULL)
		{
			tmp = *list;
			*list = tmp->next;
			tmp->next = NULL;
			free(tmp->data);
			tmp->data = NULL;
			free(tmp);
			tmp = NULL;
		}
		if (*list)
			(*list)->next = NULL;
		free((*list)->data);
		(*list)->data = NULL;
		if (list)
			free(*list);
		*list = NULL;
	}
}
