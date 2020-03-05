/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:56 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 12:57:56 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		valid_ants(char *input, t_map *map)
{
	char	*tmp;

	map->ant_count = ft_atoi(input);
	if (ft_strcmp((tmp = ft_itoa(map->ant_count)), input))
	{
		free(tmp ? tmp : NULL);
		free(input ? input : NULL);
		put_error(map, 1);
	}
	free(tmp ? tmp : NULL);
}

int			valid_map(t_map *map)
{
	t_link	*cur_link;
	int		start_link;
	int		end_link;

	start_link = 0;
	end_link = 0;
	cur_link = map->links;
	while (cur_link)
	{
		if (cur_link->start->stat == 3 || cur_link->end->stat == 3)
			end_link = 1;
		if (cur_link->start->stat == 2 || cur_link->end->stat == 2)
			start_link = 1;
		cur_link = cur_link->next;
	}
	return (end_link && start_link);
}
