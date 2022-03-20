/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:50:57 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 19:02:02 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

int	ft_iswin(t_infos *infos, int vict_condition)
{
	int	i;
	int	j;
	
	if (vict_condition == 0)
		return (0);
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] >= WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isend(t_infos *infos)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] == 64)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* TO CODE FT_ISLOST*/