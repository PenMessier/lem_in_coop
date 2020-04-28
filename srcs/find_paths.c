/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:34:11 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 13:27:53 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	ft_one_line(t_map *map)
{
	int	i;

	i = 1;
	while (i <= map->ant_count)
	{
		write(1, "L", 1);
		ft_putnbr(i);
		write(1, "-", 1);
		write(1, map->end->name, ft_strlen(map->end->name));
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	find_paths(t_map *map)
{
	ft_refill_map(map);
	if (map->ant_count != 0)
	{
		if (line_find(map->start, map->end))
			ft_one_line(map);
		else
			ft_best(map);
	}
}
