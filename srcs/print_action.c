/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:21:06 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 11:21:40 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		print_action(t_way *cool, int *action)
{
	int	*rs;
	int	*rt;
	int	*as;
	int	*at;

	rt = &cool->roomno;
	rs = &((cool - 1)->roomno);
	at = &(cool->ant);
	as = &((cool - 1)->ant);
	if (*rs >= 0 && *rt >= 0)
	{
		if (*action == 3)
			write(1, " ", 1);
		write(1, "L", 1);
		ft_putnbr(*as);
		write(1, "-", 1);
		write(1, cool->room, ft_strlen(cool->room));
		*action = 3;
	}
	*at = *as;
	*as = -1;
	if (*action < 2)
		*action = 2;
}
