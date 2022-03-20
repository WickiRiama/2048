/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover_condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:45:08 by dolee             #+#    #+#             */
/*   Updated: 2022/03/20 22:29:16 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int		check_gameover(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->size - 1)
	{
		j = 0;
		while (j < infos->size - 1)
		{
			if (infos->grid[i][j] == infos->grid[i][j + 1]
					|| infos->grid[i][j] == infos->grid[i + 1][j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < infos->size - 1)
	{
		if (infos->grid[i][infos->size - 1] == infos->grid[i + 1][infos->size - 1]
				|| infos->grid[infos->size - 1][i] == infos->grid[infos->size - 1][i + 1])
			return (0);
		i++;
	}
	return (1);
}
