/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alko_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:23:24 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/07 15:23:26 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void dots_fill(char **map, int size)
{
	int x;
	int y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		x++;
	}
}

char	**map(int size)
{
	char**	ret;
	int		i;

	if (!(ret = (char **)malloc(sizeof(char *) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = (char *)malloc(sizeof(char) * (size + 1));
		i++;
	}
	dots_fill(ret, size);
	return (ret);
}

int check_insert(t_tetro *elem, char **map)
{
	int count_hash;
	int x;
	int y;
	int point;

	count_hash = 0;
	x = 0;
	point = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (map[x][y] == '.' && (elem->x[point] + elem->y[point] == x + y + 2))
			{
				count_hash++;
				point++;
			}
			y++;
		}
		x++;
	}
	if (count_hash == 4)
		return (1);
	return (0);
}

void	fill_map(t_tetro *start, char **field)
{
	int x;
	int y;
	int point;

	while (start)
	{
		point = 0;
		if (check_insert(start, field))
		{
			x = 0;
			while (x < 4)
			{
				y = 0;
				while (y < 4)
				{
					if (field[x][y] == '.')
					{
						field[x][y] = start->symbol;
						point++;
					}
					y++;
				}
				x++;
			}
		}
		start = start->next;
	}
}

int		main(void)
{
	t_tetro *lst;

	int x1[] = { 0, 0, 1, 1 };
	int y1[] = { 1, 2, 0, 1 };
	int x2[] = { 1, 1, 0, 0 };
	int y2[] = { 0, 1, 1, 2 };
	// int x3[] = { 1, 1, 0, 0 };
	// int y3[] = { 0, 1, 1, 2 };
	lst = lstnew(x1, y1, 'A');

	// lstadd(lst, x2, y2, 'B');
	// lstadd(lst, x3, y3, 'C');
	 
	char **field = map(4);
	fill_map(lst, field);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%c ", field[i][j]);
		}
		printf("\n");
	}
	return (0);
}
