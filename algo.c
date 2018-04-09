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

static int	enable_position(t_tetro *elem, char **m, int size, t_coord cell)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (elem->x[i] + cell.x >= size || elem->y[i] + cell.y >= size ||
		m[elem->x[i] + cell.x][elem->y[i] + cell.y] != '.')
			return (0);
	return (1);
}

static void	erase_elem(t_tetro *elem, char **m, int size)
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
}

static void	shift_position(t_coord *cell, int size)
{
	if (cell->y == size - 1)
	{
		cell->x++;
		cell->y = 0;
	}
	else
		cell->y++;
}

static void	fill(char **m, t_tetro *elem, t_coord cell)
{
	int i;

	i = -1;
	while (++i < 4)
		m[elem->x[i] + cell.x][elem->y[i] + cell.y] = elem->symbol;
}

int			put_to_matrix(t_tetro *elem, char **m, int size, t_coord cell)
{
	t_coord	zero;

	if (enable_position(elem, m, size, cell))
	{
		fill(m, elem, cell);
		if (elem->next == 0)
			return (1);
		zero.x = 0;
		zero.y = 0;
		if (!put_to_matrix(elem->next, m, size, zero))
		{
			erase_elem(elem, m, size);
			shift_position(&cell, size);
			return (put_to_matrix(elem, m, size, cell));
		}
		return (1);
	}
	else
	{
		if (cell.x == size - 1 && cell.y == size - 1)
			return (0);
		shift_position(&cell, size);
		return (put_to_matrix(elem, m, size, cell));
	}
}
