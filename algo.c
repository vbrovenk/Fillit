/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:29:45 by osamoile          #+#    #+#             */
/*   Updated: 2018/04/08 17:29:47 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
//#include <stdio.h>


int		enable_position(t_tetro *elem, char **m, int size, int x, int y)
{
	int 	i;

	i = -1;
	while (++i < 4)
		if (elem->x[i] + x >= size || elem->y[i] + y >= size ||
		m[elem->x[i] + x][elem->y[i] + y] != '.')
			return (0);
	return (1);
}

void	erase_elem(t_tetro *elem, char **m, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (m[i][j] == elem->symbol)
				m[i][j] = '.';
	}
	//printf("erasing %c\n", elem->symbol);
}


int		put_to_matrix(t_tetro *elem, char **m, int size, int x, int y)
{
	int		i;

	if (enable_position(elem, m, size, x, y))
	{
		i = -1;
		while (++i < 4)
			m[elem->x[i] + x][elem->y[i] + y] = elem->symbol;
		//printf("filling %c\n", elem->symbol);
//		show_matrix(m, size);
		if (elem->next == 0)
			return (1);
		//printf("starting placing %c\n", elem->next->symbol);
		if (!put_to_matrix(elem->next, m, size, 0, 0))
		{
			erase_elem(elem, m, size);
			if (y == size - 1)
			{
				x++;
				y = 0;
			}
			else
				y++;
			return(put_to_matrix(elem, m, size, x, y));
		}
		return (1);
	}
	else
	{
		if (x == size - 1 && y == size - 1)
		{
			//printf("going back from %c\n", elem->symbol);
			return (0);
		}
		else
		{
			if (y == size - 1)
			{
				x++;
				y = 0;
			}
			else
				y++;
			return(put_to_matrix(elem, m, size, x, y));
//			return (1);
		}

	}
}


