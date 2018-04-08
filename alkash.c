/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alkash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:22:26 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/08 17:22:28 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

void print_map(char **matrix, int size)
{
	int i;
	int j;
	
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			write(1, &matrix[i][j], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);

}

void reset_position(char **matrix, t_tetro *elem, int size)
{
	int x;
	int y;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			if (matrix[x][y] == elem->symbol)
				matrix[x][y] = '.';
		}
	}
}

int check_position(char **matrix, t_tetro *elem, int size, int x, int y)
{
	int point;

	point = -1;
	while (++point < size)
	{
		if ((elem->x[point] + x >= size) || (elem->y[point] + y >= size)
			|| matrix[elem->x[point] + x][elem->y[point] + y] != '.')
			return (0);
	}
	return (1);
}

int fill_tetr(char **matrix, t_tetro *elem, int size, int x, int y)
{
	int point;

	if (check_position(matrix, elem, size, x, y))
	{
		point = -1;
		while (++point < size)
			matrix[elem->x[point] + x][elem->y[point] + y] = elem->symbol;
		return (1);
	}
	else
	{
		if (x == size - 1 && y == size - 1)
		{
			printf("Small map\n");
			return (0);
		}
		else if (y == size - 1)
		{
			fill_tetr(matrix, elem, size, x + 1, 0);
		}
		else
			fill_tetr(matrix, elem, size, x, y + 1);
	}
	return (0);
}

int fill_map(char **matrix, t_tetro *start, int size, int x, int y)
{
	if (start == NULL)
		return (1);
	
	while (start)
	{
		if (fill_tetr(matrix, start, size, x, y))
		{
			if (fill_map(matrix, start->next, size, x, y))
				return (1);
			reset_position(matrix, start, size);
		}
		
	}
	return (0);
}

char **map(int size)
{
	int i;
	int j;
	char **field;

	if (!(field = (char**)malloc(sizeof(char*) * size)))
		return (0);
	i = -1;
	while (++i < size)
		field[i] = (char*)malloc(sizeof(char) * size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			field[i][j] = '.';
	}
	return (field);
}

int main(int argc, char **argv)
{
	t_tetro *lst;

	int x1[] = { 0, 1, 2, 2 };
	int y1[] = { 1, 1, 0, 1 };

	int x2[] = { 0, 1, 1, 2 };
	int y2[] = { 1, 0, 1, 0 };

	lst = lstnew(x1, y1, 'A');
	lstadd(lst, x2, y2, 'B');
	int size = 4;
	int x = 0;
	int y = 0;
	char **square = map(size);
	fill_map(square, lst, size, x, y);
	print_map(square, size);
	


	return (0);
}
