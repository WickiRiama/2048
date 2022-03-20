/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:29:11 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 11:49:00 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "ft_2048.h"

/*
 * return 0 when success
 * return 1 when the grid is full
 */
int	add_number(t_infos *infos)
{
	int	i;
	int	j;
	int	count_empty;
	int	rand_pos;

	count_empty = 0;
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] == 0)
				count_empty++;
			j++;
		}
		i++;
	}
	if (count_empty == 0)
		return (1);
	rand_pos = rand() % count_empty;
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] == 0)
				rand_pos--;
			if (rand_pos == 0 || rand_pos == -1)
			{
				infos->grid[i][j] = (rand() % 10 == 0) ? 4 : 2;
				break;
			}
			j++;
		}
		i++;
	}
	return (0);
}
