/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:30 by frenna            #+#    #+#             */
/*   Updated: 2020/02/27 15:13:57 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void 			input(t_meta *all)
{
	int			i;
	int			j;
	t_link	*curr;

	i = 0;
	curr = all->links;
	all->n = all->room_count;
	all->s = all->start->i;
	all->t = all->end->i;
	all->c = (int *)malloc(all->room_count * all->room_count * sizeof(int));
	all->f = (int *)malloc(all->room_count * all->room_count * sizeof(int));
	all->d = (int *)malloc(all->room_count * sizeof(int));
	all->q = (int *)malloc(all->room_count * sizeof(int));
	all->ptr = (int *)malloc(all->room_count * sizeof(int));
	while (i < all->room_count * all->room_count)
	{
		all->c[i] = 0;
		all->f[i] = 0;
		i++;
	}
	while (curr)
	{
		i = curr->start->i;
		j = curr->end->i;
		all->c[i * all->room_count + j] = 1;
		all->c[j * all->room_count + i] = 1;
		curr = curr->next;
	}
}
