/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:56 by frenna            #+#    #+#             */
/*   Updated: 2020/02/26 16:12:29 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

void		valid_ants(char *input, t_meta *map)
{
	char	*tmp;

	map->ant_count = ft_atoi(input);
	if (ft_strcmp((tmp = ft_itoa(map->ant_count)), input))
	{
		free(tmp ? tmp : NULL);
		free(input);
		put_error(map, 1);
	}
	free(tmp ? tmp : NULL);
}
