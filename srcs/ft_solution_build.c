/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_build.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:09:44 by Elena             #+#    #+#             */
/*   Updated: 2020/04/28 15:54:35 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void			solution_destroy(t_solution *solution)
{
	free(solution->paths);
	free(solution->ants_per_path);
	free(solution);
}

static int		path_length(t_room *origin)
{
	int			len;

	len = 0;
	while (origin != NULL)
	{
		++len;
		origin = origin->succ;
	}
	return (len);
}

static t_path	*init_paths(int n_paths, t_room const *start, t_map *map)
{
	t_path		*paths;
	t_list		*links;
	t_line		*l;
	int			i;

	if (!(paths = (t_path *)malloc(n_paths * sizeof(t_path))))
		put_error(map, ALLOCERR);
	links = start->links;
	i = 0;
	while (i < n_paths)
	{
		l = links->data;
		if (l->dst->pred != NULL)
		{
			paths[i].origin = l->dst;
			paths[i].length = path_length(l->dst);
			++i;
		}
		links = links->next;
	}
	return (paths);
}

static void		sort_paths(int n_paths, t_path *paths)
{
	int			i;
	int			j;
	t_path		tmp;

	i = 0;
	while (i < n_paths - 1)
	{
		j = i + 1;
		while (j < n_paths)
		{
			if (paths[i].length > paths[j].length)
			{
				tmp = paths[i];
				paths[i] = paths[j];
				paths[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

t_solution		*solution_build(t_map *map, t_room const *start, int n_paths)
{
	t_solution	*solution;

	if (!(solution = (t_solution *)malloc(sizeof(t_solution))))
		put_error(map, ALLOCERR);
	solution->n_paths = n_paths;
	solution->paths = init_paths(n_paths, start, map);
	sort_paths(n_paths, solution->paths);
	if (!(solution->ants_per_path = (int *)malloc(n_paths * sizeof(int))))
		put_error(map, ALLOCERR);
	distribute_ants(map->ant_count, solution);
	return (solution);
}
