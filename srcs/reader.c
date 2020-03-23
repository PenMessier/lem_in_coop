/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elena <Elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:06:05 by Elena             #+#    #+#             */
/*   Updated: 2020/03/23 09:36:19 by Elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"


static char	*save_start_end(char *input)
{
	int				l;
	int				i;
	char			*dst;

	l = 0;
	i = 0;
	while (input[l] != ' ')
		l++;
	dst = (char *)malloc(sizeof(char) * l + 1);
	while (i < l)
	{
		dst[i] = input[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	write_start_end(int fd, char *start, char *end)
{
	write (fd, "\t\"start\": \"", 11);
	write (fd, start, ft_strlen(start));
	write (fd, "\"", 1);
	write (fd, ",\n", 2);
	write (fd, "\t\"end\": \"", 9);
	write (fd, end, ft_strlen(end));
	write (fd, "\"\n", 2);
	free (start ? start : NULL);
	free (end ? end : NULL);
}

static void	reader(int fd)
{
	char 			*input;
	char			*start;
	char			*end;
	int				check;
	int				f;

	f = 2;
	check = 0;
	while (get_next_line(0, &input))
	{
		if (f == 0 || f == 1)
		{
			if (f == 0)
				start = save_start_end(input);
			if (f == 1)
				end = save_start_end(input);
			f = 3;
		}
		ft_write_in_file(fd, input, &f, &check);
		free(input ? input : NULL);
	}
	if (f == 5)
		write (fd, "\n\t],\n", 5);
	write_start_end(fd, start, end);
	write (fd, "}\n", 2);
}

int					main(int ac, char **av)
{
	int				fd;
	
	if (ac == 2)
	{
		fd = open(av[1], O_WRONLY);
		reader(fd);
		close(fd);
	}
	return (0);
}
