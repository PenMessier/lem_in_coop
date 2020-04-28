/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:58:30 by frenna            #+#    #+#             */
/*   Updated: 2020/04/28 18:30:06 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"
# include "datatypes.h"
# include <errno.h>

/*
** Parse input functions
*/

void				init_map(t_map *map);
int					ft_parse(char *input, t_map *map, int *nl);
void				fill_map(t_map *lemin, int fd);

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
** Find paths and ant distribution functions
*/

void				find_paths(t_map *map);
void				ft_refill_map(t_map *lemin);
int					ft_max_link(t_map *lemin);
void				ft_best(t_map *map);
int					find_more_paths(t_map *map);
int					find_shortest_path(t_room *start, t_room *end, t_map *map);
void				modify_graph(t_map *map);
void				restore_graph(t_map *map);
void				combine_paths(t_room *start, t_room *end);
void				solution_improve(t_solution **best_solution,
						t_map *map, t_room *start, int path_count);
t_solution			*solution_build(t_map *map, t_room const *start,
								int n_paths);
void				solution_destroy(t_solution *solution);
void				distribute_ants(int total_ants, t_solution *solution);

/*
** Ant distribution algorithm
*/

void				ft_act(t_way *cool, t_map *map, int *ant, int *action);
void				ft_rerot(t_way *cool, int *ant, int *j, int *action);
void				ft_rotate(int max, int flow, t_way *cool, t_map *map);

/*
** Room structure utility functions
*/

t_room				*create_new_room(int x, int y, int li, char *name);
int					add_room(t_room *new, t_map *map, int *nl);
t_room				*find_room(t_room *rooms, char *name);
int					count_index_rooms(t_room *rooms);

/*
** Link structure utility functions
*/

int					add_link(t_link **links, t_room *start, t_room *end);

/*
** Way structure utility functions
*/

void				ft_becool(t_way *cool, int *wae, t_map *map);
void				ft_full(t_way *cool, int max, int row);

/*
** Print output functions
*/

void				print_action(t_way *cool, int *action);
void				ft_print_room_links(t_list *link);
void				ft_print_list_links(t_list *link);
void				ft_print_rooms(t_room *room);
void				ft_print_links(t_link *link);
void				ft_print(t_map *map);

/*
** Error and memory management functions
*/

void				put_error(t_map *map, int error);
void				free_struct(t_map *map);
void				free_list(t_list **list);
void				free_list_line(t_list **list);

/*
** Functions to send data in json file
*/

void				write_ants(int fd, char *input, int *f);
void				write_room(int fd, char *input);
void				write_link(int fd, char *input);
void				write_step(int fd, char *input, int *check);
int					ft_write_in_file(int fd, char *input, int *f, int *check);

#endif
