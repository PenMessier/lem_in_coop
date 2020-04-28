/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:48:34 by frenna            #+#    #+#             */
/*   Updated: 2020/04/27 18:40:16 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void	put_error(t_map *map, int error)
{
	free_struct(map ? map : NULL);
	if (error == -1)
		ft_putstr_fd("Error: ants number is invalid\n", 2);
	else if (error == -2 || error == -3)
		ft_putstr_fd("Error: invalid start/end room number\n", 2);
	else if (error == -4)
		ft_putstr_fd("Error: invalid room format\n", 2);
	else if (error == -5)
		ft_putstr_fd("Error: memory allocation failed\n", 2);
	else if (error == -6)
		ft_putstr_fd("Error: invalid link format\n", 2);
	else if (error == -7)
		ft_putstr_fd("Error: linked unexisted room\n", 2);
	else if (error == -8)
		ft_putstr_fd("Error: room names are duplicated\n", 2);
	else if (error == -9)
		ft_putstr_fd("Error: no start-end connection\n", 2);
	else if (error == -10)
		ft_putstr_fd("Error: no rooms\n", 2);
	else if (error == -11)
		ft_putstr_fd("Error: no links\n", 2);
	else if (error == -12)
		ft_putstr_fd("Error: invalid file format\n", 2);
	exit(EXIT_FAILURE);
}
