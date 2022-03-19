/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:15:54 by mriant            #+#    #+#             */
/*   Updated: 2022/03/19 16:43:16 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_2048.h"

int	main(void)
{
	int		grid_size;
	void	**windows;
	int		i;
	int		j;
	
	initscr();
	cbreak();
	noecho();
	clear();
	grid_size = ft_menu(LINES, COLS);
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