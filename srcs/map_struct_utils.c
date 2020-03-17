/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:18 by Elena             #+#    #+#             */
/*   Updated: 2020/03/16 19:19:44 by Elena            ###   ########.fr       */
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

int			fill_map(t_map *lemin)
{
	int		nl;
	int		isvalid;
	char	*input;

	nl = 2;
	isvalid = 1;
	init_map(lemin);
	while (get_next_line(0, &input))
	{
		ft_putstr(input);
		write(1, "\n", 1);
		if (isvalid && !ft_parse(input, lemin, &nl))
			isvalid = 0;
		free(input ? input : NULL);
	}
	write(1, "\n", 1);
	if (!lemin->rooms || !lemin->links || !lemin->start || !lemin->end || !isvalid)
		return (0);
	lemin->room_count = count_index_rooms(lemin->rooms);
	if (!valid_map(lemin))
		return (0);
	assign_level(lemin, 0);
	check_end_level(lemin);
	lemin->dead_end_lvl = find_dead_end(lemin, lemin->end->level - 1);
	return (1);
}
