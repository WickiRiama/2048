/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 04:45:55 by dolee             #+#    #+#             */
/*   Updated: 2022/03/20 14:41:32 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2048.h"

void	draw_numbers(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j])
			{
				wclear(infos->boxes[i][j]);
				mvwprintw(infos->boxes[i][j],
						infos->box_height / 2,
						infos->box_width / 2,
						"%d\n",
						infos->grid[i][j]);
				box(infos->boxes[i][j], 0, 0);
			}
			else
			{
				wclear(infos->boxes[i][j]);
				box(infos->boxes[i][j], 0, 0);
			}
			j++;
		}
		i++;
	}
}
