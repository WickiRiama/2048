/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:15:42 by dolee             #+#    #+#             */
/*   Updated: 2022/03/20 09:00:43 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_2048.h"

int	init_grid(t_infos *infos)
{
	int		i;
	int		j;

	infos->box_height = LINES / infos->size;
	infos->box_width = COLS / infos->size;
	if (!(infos->boxes = malloc(sizeof(WINDOW *) * 25)))
		return (1);
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			infos->boxes[i][j] = newwin(infos->box_height, infos->box_width, i * infos->box_height, j * infos->box_width);
			box(infos->boxes[i][j], 0, 0);
			if (infos->grid[i][j])
				mvwprintw(infos->boxes[i][j],
						infos->box_height / 2,
						infos->box_width / 2,
						"%d\n",
						infos->grid[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
