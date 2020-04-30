/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:32 by frenna            #+#    #+#             */
/*   Updated: 2020/04/29 14:04:58 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>

# define BUFF_SIZE 10

typedef	struct		s_node
{
	char			*content;
	int				fd;
	size_t			content_size;
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);
void				ft_init(t_node **s, char *content, int fd, size_t c_size);
void				ft_line(t_node **s, char **line, int fd);
void				ft_size(t_node **s, int fd, char **line, size_t f);
size_t				ft_r(int fd, ssize_t rd, t_node **s, char *buff);
int					ft_atoi(const char *s);

/*
** Copies the values of n bytes from the location pointed to by src
** directly to the memory block pointed to by dest.
*/

void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strrchr(const char *str, int ch);
char				**ft_strsplit(const char *str, char c);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_count_words(const char *str, char c);
void				ft_putnbr(int nb);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
int					ft_abs(int nbr);
char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
int					ft_free_array(char **array, int ret_val);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memalloc(size_t size);

/*
** Allocates (with malloc()) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
*/
char				*ft_strnew(size_t size);

/*
** Takes as a parameter the address of a string that
** need to be freed with free(), then sets its pointer to NULL.
*/
void				ft_strdel(char **as);

/*
** Checks if an array of integers is sorted.
*/
int					ft_is_sorted(int *arr, int n);
int					ft_strcmp(const char *s1, const char *s2);

#endif
