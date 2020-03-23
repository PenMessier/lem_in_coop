/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 09:26:27 by Elena             #+#    #+#             */
/*   Updated: 2020/03/23 10:21:09 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

static void	comment_opt(char *input, int *f)
{
	if (!ft_strcmp(input, "##start"))
		*f = 0;
	else if (!ft_strcmp(input, "##end"))
		*f = 1;
}

static void	room_opt(int fd, char *input, int *check, int *f)
{
	int		x;
	int		y;
	int		len;

	x = 0;
	y = 0;
	len = 0;
	if (!valid_line_room(input, &x, &y, &len))
	{
		*f = 4;
		*check = 0;
		write (fd, "\n\t},\n\t\"links\": [\n", 17);
	}
	else
	{
		if (*check)
			write (fd, ",\n", 2);
		write_room(fd, input);
		*check = 1;
	}
}

static int	link_opt(int fd, char *input, int *check, int *f)
{
	if (!ft_strrchr(input, '-'))
	{
		write (fd, "\n\t],\n", 5);
		write (fd, "\t\"steps\": [\n", 12);
		*f = 5;
		*check = 0;
		return (0);
	}
	else
	{
		if (*check)
			write (fd, ",\n", 2);
		write_link(fd, input);
		*check = 1;
	}
	return (1);
}

int					ft_write_in_file(int fd, char *input, int *f, int *check)
{
	if (input[0] == '#')
	{
		comment_opt(input, f);
		return (1);
	}
	if (*f == 2)
	{
		write_ants(fd, input, f);
		return (1);
	}
	if (*f == 3)
		room_opt(fd, input, check, f);
	if (*f == 4)
	{
		if (!link_opt(fd, input, check, f))
			return (1);
	}
	if (*f == 5)
	{
		if (*check)
			write (fd, ",\n", 2);
		write_step(fd, input);
		*check = 1;
	}
	return (1);
}
