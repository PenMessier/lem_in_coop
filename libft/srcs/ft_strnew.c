/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:23:42 by frenna            #+#    #+#             */
/*   Updated: 2020/03/12 12:56:15 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (0);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memset(str, (int)'\0', (size + 1) * sizeof(char));
	return (str);
}
