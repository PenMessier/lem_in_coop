/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:36:41 by frenna            #+#    #+#             */
/*   Updated: 2020/02/28 13:06:30 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem.h"

int imin(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
