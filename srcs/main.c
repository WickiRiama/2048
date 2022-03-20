/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:15:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 23:31:00 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "libft.h"
#include "ft_2048.h"

int	ft_check_power2(int value)
{
	if (value < 0)
		return (0);
	while (value / 2 > 1)
		value = value / 2;
	if (value == 1)
		return (0);
	else
		return (1);
}

static int	init_ncurses()
{
	if (!initscr())
		return (1);
	if (cbreak() || noecho() || nodelay(stdscr, TRUE))
	{
		endwin();
		return (1);
	}
	curs_set(0);
	return (0);
}

static int init_infos(t_infos *infos)
{
	int		i1;
	int		j1;
	int		i2;
	int		j2;

	if (!(infos->grid = ft_calloc(25, sizeof(int))))
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

void	ft_clean_win(t_infos *infos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < infos->size && infos->boxes)
	{
		j = 0;
		while (j < infos->size && infos->boxes[i][j])
		{
			delwin(infos->boxes[i][j]);
			j++;
		}
		if (j < infos->size)
			break;
		i++;
	}
	free(infos->boxes);
}

static WINDOW *draw_victory()
{
	WINDOW *window;

	window = newwin(10, COLS, 0, 0);
	if (!window)
		return (NULL);
	clear();
	refresh();
	if (keypad(window, TRUE))
		return (NULL);
	mvwprintw(window, 1, COLS / 2, "VICTORY\n");
	box(window, 0, 0);
	wrefresh(window);
	return (window);
}

static int	victory()
{
	WINDOW *window;
	int	key;

	window = draw_victory();
	key = wgetch(window);
	while (1)
	{
		if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		{
			delwin(window);
			clear();
			refresh();
			return (0);
		}
		else if (key == KEY_RESIZE)
		{
			delwin(window);
			clear();
			refresh();
			return (1);
		}
		else if (key == 27 || key == 3)
		{
			delwin(window);
			clear();
			refresh();
			return (1);
		}
	}
}

static int	check_victory(t_infos *infos)
{
	static int already_victory = 0;
	int		i;
	int		j;

	if (already_victory)
		return (0);
	i = 0;
	while (i < infos->size)
	{
		j = 0;
		while (j < infos->size)
		{
			if (infos->grid[i][j] == WIN_VALUE)
			{
				if (victory())
					return (1);
				already_victory = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}



#include <unistd.h>
int	main(void)
{
	t_infos	infos;
	int		key;
	int		vict_condition;

	/*
	 * Set seed for random number
	 */
	srand(time(NULL));

	vict_condition = ft_check_power2(WIN_VALUE);
	/*
	 * Initialize ncurses screen and set configurations
	 */
	if (init_ncurses())
		return (1);

	/*
	 * Menu window
	 * t_infos.size will be initialized here
	 */
	if(ft_menu(&infos))
	{
		endwin();
		return (0);
	}
	refresh();

	/*
	 * Initialize t_infos.grid and t_infos.score
	 * t_infos.size has been set on ft_menu
	 */
	if (init_infos(&infos))
	{
		endwin();
		return (1);
	}

	/*
	 * Initialize grids and draw
	 */
	if (init_grid(&infos))
	{
		ft_clean_win(&infos);
		free(infos.grid);
		endwin();
		return (1);
	}
	refresh_grid(&infos);

	while (1)
	{
		key = wgetch(infos.boxes[0][0]);
		if (key == KEY_LEFT)
		{
			if (move_left(&infos))
				continue;
		}
		else if (key == KEY_RIGHT)
		{
			if (move_right(&infos))
				continue ;
		}
		else if (key == KEY_UP)
		{
			if (move_up(&infos))
				continue ;
		}
		else if (key == KEY_DOWN)
		{
			if (move_down(&infos))
				continue ;
		}
		else if (key == KEY_RESIZE)
		{
			ft_clean_win(&infos);
			clear();
			refresh();
			init_grid(&infos);
			refresh_grid(&infos);
			continue;
		}
		// 3 = CTRL+C and 27 = ESC
		else if (key == 27 || key == 3)
			break ;
		else
			continue ;
		if (add_number(&infos))
			if (check_gameover(&infos))
			{
				draw_numbers(&infos);
				refresh_grid(&infos);
				break;
			}
		draw_numbers(&infos);
		refresh_grid(&infos);
		if (check_victory(&infos))
			break ;

	}
	ft_clean_win(&infos);
	free(infos.grid);
	endwin();
	return (0);
}
