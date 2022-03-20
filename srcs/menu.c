/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:59 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 17:32:15 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_2048.h"

static WINDOW	*draw_menu()
{
	WINDOW	*window;

	window = newwin(LINES, COLS, 0, 0);
	if (!window)
		return (NULL);
	clear();
	refresh();
	if (keypad(window, TRUE))
		return (NULL);
	mvwprintw(window, 1, COLS / 2, "2048\n");
	mvwprintw(window, 2, 1,
			"Welcome.\n"
			" This *FUN* game is provided to you by dolee and mriant.\n"
			" Please press LEFT to play with a 4x4 grid, or RIGHT to play with a 5x5 grid.\n");
	box(window, 0, 0);
	wrefresh(window);
	return (window);
}

static WINDOW	*get_key_input(t_infos *infos, WINDOW *window)
{
	int		key;

	while (1)
	{
		key = wgetch(window);
		if (key == KEY_LEFT)
		{
			infos->size = 4;
			return (window);
		}
		else if (key == KEY_RIGHT)
		{
			infos->size = 5;
			return (window);
		}
		else if (key == KEY_RESIZE)
		{
			delwin(window);
			clear();
			refresh();
			window = draw_menu();
			continue;
		}
		// 3 = CTRL+C and 27 = ESC
		else if (key == 27 || key == 3)
		{
			delwin(window);
			return (NULL);
		}
	}
}

int	ft_menu(t_infos *infos)
{
	WINDOW	*window;

	clear();
	refresh();
	window = draw_menu();
	window = get_key_input(infos, window);
	if (!window)
		return (1);
	wclear(window);
	delwin(window);
	clear();
	refresh();
	return (0);
}
