/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:56 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 12:05:36 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int			valid_ants(char *input, t_map *map)
{
	char	*tmp;

	tmp = NULL;
	map->ant_count = ft_atoi(input);
	if (map->ant_count < 0 || ft_strcmp((tmp = ft_itoa(map->ant_count)), input))
	{
		free(tmp ? tmp : NULL);
		return (0);
	}
	free(tmp ? tmp : NULL);
	return (1);
}

int			valid_map(t_map *map)
{
	t_link	*cur_link;
	int		start_link;
	int		end_link;

	start_link = 0;
	end_link = 0;
	cur_link = map->links;
	if (!map->rooms)
		return (-10);
	if (!map->links)
		return (-11);
	if (!map->start || !map->end)
		return (-2);
	while (cur_link)
	{
		if (cur_link->start->stat == 3 || cur_link->end->stat == 3)
			end_link = 1;
		if (cur_link->start->stat == 2 || cur_link->end->stat == 2)
			start_link = 1;
		cur_link = cur_link->next;
	}
	if (!end_link || !start_link)
		return (-9);
	return (1);
}
