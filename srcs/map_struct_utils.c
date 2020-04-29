/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:18 by Elena             #+#    #+#             */
/*   Updated: 2020/04/29 11:16:07 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		init_map(t_map *map)
{
	map->rooms = NULL;
	map->links = NULL;
	map->start = NULL;
	map->end = NULL;
	map->list = NULL;
}

void		fill_map(t_map *lemin, int fd)
{
	int		nl;
	int		f;
	int		isvalid;
	char	*input;

	nl = 2;
	init_map(lemin);
	while ((f = get_next_line(fd, &input)) > 0)
	{
		if ((isvalid = ft_parse(input, lemin, &nl)) < 0)
		{
			free(input ? input : NULL);
			put_error(lemin, isvalid);
		}
		ft_putstr(input);
		write(1, "\n", 1);
		free(input ? input : NULL);
	}
	if (f < 0)
		put_error(lemin, -12);
	write(1, "\n", 1);
	if ((nl = valid_map(lemin)) < 0)
		put_error(lemin, nl);
	lemin->room_count = count_index_rooms(lemin->rooms);
}
