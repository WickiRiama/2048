/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:29:11 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 06:10:01 by dolee            ###   ########.fr       */
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
	int	*blanks[25];

	count_empty = 0;
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] == 0)
			{
				blanks[count_empty] = infos->grid[i] + j;
				count_empty++;
			}
			j++;
		}
		i++;
	}
	if (count_empty == 0)
		return (1);
	rand_pos = rand() % count_empty;
		*blanks[rand_pos] = (rand() % 10 == 0) ? 4 : 2;
	return (0);
}
