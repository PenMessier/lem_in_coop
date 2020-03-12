/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:18 by Elena             #+#    #+#             */
/*   Updated: 2020/03/12 12:44:25 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		init_map(t_map *map)
{
	map->rooms = NULL;
	map->links = NULL;
	map->start = NULL;
	map->end = NULL;
	map->all = NULL;
}

void		fill_map(t_map *lemin)
{
	int		nl;
	char	*input;

	nl = 2;
	init_map(lemin);
	while (get_next_line(0, &input))
	{
		ft_parse(input, lemin, &nl);
		free(input ? input : NULL);
		if (nl == -1)
			put_error(lemin, 1);
	}
	free(input ? input : NULL);
	lemin->room_count = count_index_rooms(lemin->rooms);
	if (!valid_map(lemin))
		put_error(lemin, 8);
	assign_level(lemin, 0);
	check_end_level(lemin);
}

