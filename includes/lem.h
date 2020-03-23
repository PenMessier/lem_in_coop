/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:58:30 by frenna            #+#    #+#             */
/*   Updated: 2020/03/23 09:28:42 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "../libft/libft.h"
# include <errno.h>

typedef struct		s_room
{
	int				i;
	char			*name;
	int				x;
	int				y;
	int				stat;
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

typedef struct		s_meta
{
	int				n;
	int				s;
	int				t;
	int				*c;
	int				*f;
	int				*d;
	int				*ptr;
	int				*q;
}					t_meta;

typedef struct		s_way
{
	int				roomno;
	int				ant;
	char			*room;
}					t_way;

typedef struct		s_map
{
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;
	t_meta			*all;
	int				dead_end_lvl;
	int				ant_count;
	int				room_count;
}					t_map;

/*
** Parse input functions
*/

void				init_map(t_map *map);
void				ft_init_meta(t_meta *meta);
int					ft_parse(char *input, t_map *map, int *nl);
int					fill_map(t_map *lemin, int fd);

/*
** Validation functions
*/

int					valid_ants(char *input, t_map *map);
int					valid_room(char *input, t_map *map, int *nl);
int					valid_link(char *input, t_map *map);
int					valid_map(t_map *map);
int					valid_line_room(char *s, int *x, int *y, int *li);
int					find_coord(char *s, int *i);


/*
** Dinic algorithm functions
*/

int					bfs(t_meta *dub);
int					dfs (int v, int flow, t_meta *dub);
int					dinic(t_meta *all);

/*
** Ant distribution algorithm
*/

void					ft_act(t_way *cool, t_map *map, int *ant, int *action);
void				ft_rerot(t_way *cool, int *ant, int *j, int *action);
void				ft_rotate(int max, int flow, t_way *cool, t_map *map);
void				ft_queen(int max, int flow, int *wae, t_map *map);
void				find_paths(t_map *map);

/*
** Meta structure utility functions
*/

int					create_link_matrix(t_map *map);
int					ft_min(int a, int b);
int					ft_dub(t_meta *all, t_meta *dub);
void				ft_undub(t_meta *all, t_meta *dub);
int					ft_nodewae(t_meta *all, int *wae, int nom);

/*
** Room structure utility functions
*/

t_room				*create_new_room(int x, int y, char *name, int li);
int					add_room(t_room *new, t_map *map, int *nl);
t_room				*find_room(t_room *rooms, char *name);
int					count_index_rooms(t_room *rooms);
char				*get_room_name(t_map *map, int no);
void				assign_level(t_map *map, int level);
void				check_end_level(t_map *map);
int					find_dead_end(t_map *map, int	check_lvl);

/*
** Link structure utility functions
*/

int					add_link(t_link **links, t_room *start, t_room *end);
void				swap_rooms(t_link *link);

/*
** Way structure utility functions
*/

void				ft_becool(t_way *cool, int *wae, t_map *map);
void				ft_full(t_way *cool, int max, int row);

/*
** Print output functions
*/

void				ft_print_input(t_map map);
void				ft_pr_f(t_meta *all);
void				print_action(t_way *cool, int *action);

/*
** Error and memory management functions
*/

void				put_error(t_map *map, int r);
void				free_struct(t_map *map);
void				free_meta(t_meta *all);

/*
** Functions to send data in json file
*/

void				write_ants(int fd, char *input, int *f);
void				write_room(int fd, char *input);
void				write_link(int fd, char *input);
void				write_step(int fd, char *input);
int					ft_write_in_file(int fd, char *input, int *f, int *check);

#endif
