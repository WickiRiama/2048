/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:13:59 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 16:40:51 by mriant           ###   ########.fr       */
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

void	**ft_initgrid(int grid_size)
{
	int 	box_height;
	int		box_width;
	int		i;
	int		j;
	void	**windows;

	box_height = LINES / grid_size;
	box_width = COLS / grid_size;
	windows = malloc(sizeof(void *) * grid_size * grid_size);
	if (!windows)
		return (NULL);
	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			windows[i * grid_size + j] = newwin(box_height, box_width, i * box_height, j * box_width);
			box(windows[i * grid_size + j], 0, 0);
			wrefresh(windows[i * grid_size + j]);
			j++;
		}
		i++;
	}
	return (windows);
}