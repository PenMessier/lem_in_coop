/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:19:18 by Elena             #+#    #+#             */
/*   Updated: 2020/02/27 20:03:25 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	init_meta(t_meta *map)
{
	map->rooms = NULL;
	map->links = NULL;
	map->start = NULL;
	map->end = NULL;
	map->c = 0;
	map->f = 0;
	map->d = 0;
	map->ptr = 0;
	map->q = 0;
}

int			main(int ac, char **av)
{
	char	*input;
	t_meta	lemin;
	int		nl;

	nl = 2;
	init_meta(&lemin);
	if (ac == 1)
	{
		while (get_next_line(0, &input))
		{
			ft_parse(input, &lemin, &nl);
			free(input ? input : NULL);
			if (nl == -1)
				put_error(&lemin, 1);
		}
		lemin.room_count = count_index_rooms(lemin.rooms);
		//print_input(lemin);
		find_paths(&lemin);
		free_struct(&lemin);
	}
	av = 0;
	return (0);
}
