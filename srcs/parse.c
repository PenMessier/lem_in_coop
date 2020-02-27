/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:22:25 by Elena             #+#    #+#             */
/*   Updated: 2020/02/27 15:03:49 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

/*int		valid_map(t_meta map)
{
	t_room	*curr;
	t_link	*clink;
	
	
	return (1);
}
*/
	
void	ft_parse(char *input, t_meta *map, int *nl)
{
	if (!input)
		*nl = -1;
	if (input[0] == '#')
	{
		if (!ft_strcmp(input, "##start"))
			*nl = !map->start ? 0 : -1;
		if (!ft_strcmp(input, "##end"))
			*nl = !map->end ? 1 : -1;
		return ;
	}
	if (*nl == 2)
	{
		valid_ants(input, map);
		*nl = 3;
		return ;
	}
	if (*nl == 0 || *nl == 1 || *nl == 3)
		valid_room(input, map, nl);
	if (*nl == 4)
		valid_link(input, map);
}
