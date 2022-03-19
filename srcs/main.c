/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:15:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 17:18:46 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_2048.h"

int	main(void)
{
	void	**windows;
	t_infos	infos;
	int		i;
	int		j;
	
	initscr();
	cbreak();
	noecho();
	clear();

	/*
	 * Initialize t_infos
	 */
	infos.size = ft_menu(LINES, COLS);
	infos.grid = malloc(sizeof(int) * infos.size * info.size);
	infos.score = 0;

	clear();
	windows = ft_initgrid(grid_size);
	wgetch(windows[0]);
	i = 0;
	while (i < grid_size)
	{
		j = 0;
		{
			delwin(windows[i * grid_size + j]);
			j++;
		}
		i++;
	}

	free (windows);
	endwin();
}
