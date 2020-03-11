/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:58:30 by frenna            #+#    #+#             */
/*   Updated: 2020/03/05 13:47:26 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "../libft/libft.h"
# include <errno.h>

#define  DEBUG 0

typedef struct		s_room
{
	int				i;
	char			*name;
	int				x;
	int				y;
	int				stat; //used - 1, unused - 0, start - 2, end - 3
	int				ant;
	int				level;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
}					t_link;

typedef struct 		s_meta
{
	int				n;
	int     		s;
	int     		t;
	int				*c;
	int     		*f;
	int     		*d;
	int     		*ptr;
	int     		*q;
}					t_meta;

typedef struct		s_map
{
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;
	t_meta			*all;
	int				ant_count;
	int				room_count;
}					t_map;

void			ft_pr_f(t_meta *all);
void			create_link_matrix(t_map *map);
int				imin(int a, int b);
int				bfs(t_meta *dub);
int				dfs (int v, int flow, t_meta *dub);
int				dinic(t_meta *all);
void			ft_dub(t_meta *all, t_meta *dub);
void			ft_undub(t_meta *all, t_meta *dub);
int			tf_nodewae(t_meta *all, int *wae, int nom);
void			find_paths(t_map *map);

/*
** Parse input
*/

void				init_map(t_map *map);
void				init_meta(t_meta *meta);
void				ft_parse(char *input, t_map *map, int *nl);

/*
** Validation functions
*/

void				valid_ants(char *input, t_map *map);
void				valid_room(char *input, t_map *map, int *nl);
void				valid_link(char *input, t_map *map);
int					valid_map(t_map *map);

/*
** Error management functions
*/

void				put_error(t_map *map, int r);

/*
** Structures utility functions
*/

t_room				*create_new_room(int x, int y, char *name, int li);
int					add_room(t_room *new, t_map *map, int *nl);
t_room				*find_room(t_room *rooms, char *name);
int					count_index_rooms(t_room *rooms);
int					add_link(t_link **links, t_room *start, t_room *end);
void				swap_rooms(t_link *link);
void				free_struct(t_map *map);
void				free_meta(t_meta *all);

/*
** Assign level to rooms
*/

void				assign_level(t_map *map, int level);
void				check_end_level(t_map *map);

/*
** Print function
*/

void				print_input(t_map map);
void    ft_queen(int max, int flow, int *wae, t_map *map);

#endif
