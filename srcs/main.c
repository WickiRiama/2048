/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:15:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 18:53:43 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "ft_2048.h"

int	main(void)
{
	void	**windows;
	t_infos	infos;
	int		i;
	int		j;
	
	srand(time(NULL));
	initscr();
	cbreak();
	noecho();
	/*
	 * Initialize t_infos
	 */
	 /* MALLOC PROTECTION !!!!!*/
	infos.size = ft_menu(LINES, COLS);
	infos.grid = malloc(sizeof(int *) * infos.size);
	i = 0;
	while (i < infos.size)
	{
		infos.grid[i] = ft_calloc(sizeof(int), infos.size);
		i++;
	}
	infos.score = 0;
	ft_add_number(&infos);
	ft_add_number(&infos);
	clear();
	refresh();
	windows = ft_initgrid(infos);
	while (1)
	{
		key = wgetch(window[0]);
		if (key == KEY_LEFT)
			move_left(&infos);
		else if (key == KEY_RIGHT)
			move_right(&infos);
		else if (key == KEY_UP)
			move_up(&infos);
		else if (key == KEY_DOWN)
			move_down(&infos);
		// to code ft_printgrid();
		// to code if (stop_conditoon)
		// 	break
	}
	wgetch(windows[0]);
	i = 0;
	while (i < infos.size)
	{
		j = 0;
		{
			delwin(windows[i * infos.size + j]);
			j++;
		}
		i++;
	}

	free (windows);
	endwin();
}
