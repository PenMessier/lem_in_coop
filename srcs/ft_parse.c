/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:22:25 by Elena             #+#    #+#             */
/*   Updated: 2020/03/12 22:04:31 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int	ft_parse(char *input, t_map *map, int *nl)
{
	if (input[0] == '#')
	{
		if (!ft_strcmp(input, "##start"))
		{
			*nl = 0;
			return (!map->start ? 1 : 0);
		}
		if (!ft_strcmp(input, "##end"))
		{
			*nl = 1;
			return (!map->end ? 1 : 0);
		}
		return (1);
	}
	if (*nl == 2)
	{
		*nl = 3;
		return (valid_ants(input, map) ? 1 : 0);
	}
	if (*nl == 0 || *nl == 1 || *nl == 3)
		return (valid_room(input, map, nl) ? 1 : 0);
	if (*nl == 4)
		return (valid_link(input, map) ? 1 : 0);
	return (1);
}
