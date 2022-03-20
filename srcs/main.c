/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:15:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 11:54:14 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "ft_2048.h"


static void	init_ncurses()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, 1);
}

static int init_infos(t_infos *infos)
{
	int		i1;
	int		j1;
	int		i2;
	int		j2;

	if (!(infos->grid = calloc(25, sizeof(int))))
		return (1);
	infos->score = 0;

	i1 = rand() % infos->size;
	j1 = rand() % infos->size;

	i2 = rand() % infos->size;
	j2 = rand() % infos->size;
	while (i1 == i2 && j1 == j2)
	{
		j2 = rand() % infos->size;
		j2 = rand() % infos->size;
	}

	infos->grid[i1][j1] = (rand() % 10 == 0) ? 4 : 2;
	infos->grid[i2][j2] = (rand() % 10 == 0) ? 4 : 2;

	return (0);
}

static void refresh_grid(t_infos *infos)
{
	int		i;
	int		j;

	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while ( j < infos->size)
		{
			wrefresh(infos->boxes[i][j]);
			j++;
		}
		i++;
	}
}

#include <unistd.h>
int	main(void)
{
	t_infos	infos;
	int		i;
	int		j;
	int		key;


	/*
	 * Set seed for random number
	 */
	srand(time(NULL));

	/*
	 * Initialize ncurses screen and set configurations
	 */
	init_ncurses();

	/*
	 * Menu window
	 * t_infos.size will be initialized here
	 */
	ft_menu(&infos);
	refresh();

	/*
	 * Initialize t_infos.grid and t_infos.score
	 * t_infos.size has been set on ft_menu
	 */
	if (init_infos(&infos))
		return (1);


	/*
	 * Initialize grids and draw
	 */
	if (init_grid(&infos))
		return (1);
	refresh_grid(&infos);

	while (1)
	{
		key = wgetch(infos.boxes[0][0]);
		/*
		if (key == KEY_LEFT)
			move_left(&infos);
		else if (key == KEY_RIGHT)
			move_right(&infos);
		else if (key == KEY_UP)
			move_up(&infos);
		else if (key == KEY_DOWN)
			move_down(&infos);
		else
			continue ;*/
		add_number(&infos);

		draw_numbers(&infos);
		refresh_grid(&infos);
		// to code ft_printgrid();
		// to code if (stop_conditoon)
		// 	break
	}

	//wgetch(windows[0]);
	i = 0;
	while (i < infos.size)
	{
		j = 0;
		{
			delwin(infos.boxes[i][j];
			j++;
		}
		i++;
	}

	endwin();
}
