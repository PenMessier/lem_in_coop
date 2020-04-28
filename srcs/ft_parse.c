/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:22:25 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 11:47:32 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int	check_comands(char *input, t_map *map, int *nl)
{
	if (!ft_strcmp(input, "##start"))
	{
		*nl = 0;
		return (!map->start ? 1 : -2);
	}
	else if (!ft_strcmp(input, "##end"))
	{
		*nl = 1;
		return (!map->end ? 1 : -3);
	}
	return (0);
}

int			ft_parse(char *input, t_map *map, int *nl)
{
	int		f;

	if (input[0] == '#' && ft_strcmp(input, "##start")
	&& ft_strcmp(input, "##end"))
		return (1);
	if (*nl == 2)
	{
		*nl = 3;
		return (valid_ants(input, map) ? 1 : -1);
	}
	if ((f = check_comands(input, map, nl)))
		return (f);
	if (*nl == 0 || *nl == 1 || *nl == 3)
		if ((f = valid_room(input, map, nl)) < 0)
			return (f);
	if (*nl == 4)
		if ((f = valid_link(input, map)) < 0)
			return (f);
	return (1);
}
