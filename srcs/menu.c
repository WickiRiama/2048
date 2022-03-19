/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:59 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 18:04:57 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include "ft_2048.h"

int	ft_menu(int lines, int cols)
{
	int		key;
	int		grid_size;
	void	*window;

	window = newwin(lines, cols, 0, 0);
	keypad(window, TRUE);
	mvwprintw(window, 1, cols / 2, "2048\n");
	mvwprintw(window, 2, 1, "Welcome.\n This *FUN* game is provided to you by dolee and mriant.\n Please press LEFT to play with a 4x4 grid, or RIGHT to play with a 5x5 grid.\n");
	box(window, 0, 0);
	wrefresh(window);
	key = wgetch(window);
	while (key != KEY_LEFT && key != KEY_RIGHT)
		key = wgetch(window);
	if (key == KEY_LEFT)
		grid_size = 4;
	else
		grid_size = 5;
	delwin(window);
	return (grid_size);
}

void	**ft_initgrid(t_infos infos)
{
	int 	box_height;
	int		box_width;
	int		i;
	int		j;
	void	**windows;

	box_height = LINES / infos.size;
	box_width = COLS / infos.size;
	windows = malloc(sizeof(void *) * infos.size * infos.size);
	if (!windows)
		return (NULL);
	i = 0;
	while (i < infos.size)
	{
		j = 0;
		while (j < infos.size)
		{
			windows[i * infos.size + j] = newwin(box_height, box_width, i * box_height, j * box_width);
			mvwprintw(windows[i * infos.size + j], box_height / 2, box_width / 2, "%d\n", infos.grid[i][j]);
			box(windows[i * infos.size + j], 0, 0);
			wrefresh(windows[i * infos.size + j]);
			j++;
		}
		i++;
	}
	return (windows);
}