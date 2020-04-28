/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:26:04 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 11:26:36 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			combine_paths(t_room *start, t_room *end)
{
	t_room	*a;
	t_room	*b;

	b = end;
	while ((a = b->parent) != NULL)
	{
		if (a->pred != b && b->succ != a)
		{
			if (a != start)
				a->succ = b;
			if (b != end)
				b->pred = a;
		}
		else
		{
			if (a->pred == b)
				a->pred = NULL;
			if (b->succ == a)
				b->succ = NULL;
		}
		b = a;
	}
}
