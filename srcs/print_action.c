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

int		print_action(t_way *cool)
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
		write(1, "L", 1);
		ft_putnbr(*as);
		write(1, "-", 1);
		write(1, cool->room, ft_strlen(cool->room));
		write(1, " ", 1);
	}
	*at = *as;
	*as = -1;
	return (2);
}
