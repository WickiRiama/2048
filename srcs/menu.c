/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:59 by mriant            #+#    #+#             */
/*   Updated: 2022/03/20 09:01:10 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_2048.h"

static WINDOW	*draw_menu()
{
	WINDOW	*window;

	window = newwin(LINES, COLS, 0, 0);
	keypad(window, TRUE);
	mvwprintw(window, 1, COLS / 2, "2048\n");
	mvwprintw(window, 2, 1,
			"Welcome.\n"
			"This *FUN* game is provided to you by dolee and mriant.\n"
			"Please press LEFT to play with a 4x4 grid, or RIGHT to play with a 5x5 grid.\n");
	box(window, 0, 0);
	wrefresh(window);
	return (window);
}

static void	get_key_input(t_infos *infos, WINDOW *window)
{
	int		key;

	while (1)
	{
		key = wgetch(window);
		if (key == KEY_LEFT)
		{
			infos->size = 4;
			return ;
		}
		else if (key == KEY_RIGHT)
		{
			infos->size = 5;
			return ;
		}

	}
}

void	ft_menu(t_infos *infos)
{
	WINDOW	*window;

	window = draw_menu();
	get_key_input(infos, window);
	wclear(window);
	delwin(window);
}
