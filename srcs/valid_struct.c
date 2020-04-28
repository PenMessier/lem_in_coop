/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:03:48 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 12:07:31 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static int	valid_line_link(char *s)
{
	int		min;

	min = 0;
	while (*s)
	{
		min = *s == 45 ? min + 1 : min;
		s++;
	}
	return (min);
}

int			valid_link(char *input, t_map *map)
{
	int		mi;
	char	**t;
	t_room	*start;
	t_room	*end;

	if (!(mi = valid_line_link(input)))
		return (-6);
	t = ft_strsplit(input, '-');
	if (!(start = find_room(map->rooms, t[0]))
		|| !(end = find_room(map->rooms, t[1])))
	{
		ft_free_array(t, 1);
		return (-7);
	}
	else
	{
		if (!add_link(&map->links, start, end))
			return (-5);
	}
	ft_free_array(t, 1);
	return (1);
}

int			valid_room(char *input, t_map *map, int *nl)
{
	int		x;
	int		y;
	int		li;
	int		f;

	if (!valid_line_room(input, &x, &y, &li))
	{
		if (valid_line_link(input))
		{
			*nl = 4;
			return (1);
		}
		else
			return (-4);
	}
	if ((f = add_room(create_new_room(x, y, li, input),
		map, nl)) < 0)
		return (f);
	return (1);
}
