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
#include <stdio.h>

void	show_matrix(char **m, int size)
{
	int		i;
	int		j;

	i = -1;
	while(++i < size)
	{
		j = -1;
		while (++j < size)
			printf("%c ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

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

void	put_to_matrix(t_tetro *elem, char **m, int size, int x, int y)
{
	int		i;

	if (enable_position(elem, m, size, x, y))
	{
		i = -1;
		while (++i < 4)
			m[elem->x[i] + x][elem->y[i] + y] = elem->symbol;
	}
	else
	{
		if (x == size - 1 && y == size - 1)
		{
			printf("where is not place\n");
			return ;
		}
		if (y == size - 1)
			put_to_matrix(elem, m, size, x + 1, 0);
		else
			put_to_matrix(elem, m, size, x, y + 1);
	}
}

char	**create_matrix(int size)
{
	char	**m;
	int		i;
	int		j;

	m = (char**)malloc(sizeof(char*) * size);
	i = -1;
	while (++i < size)
	{
		m[i] = (char*)malloc(sizeof(char) * size);
		j = -1;
		while (++j < size)
			m[i][j] = '.';
	}
	return (m);
}

int		main(void)
{
	t_tetro *lst;
	char	**matrix;
	int		size;

	int x1[] = { 0, 1, 2, 3 };
	int y1[] = { 0, 0, 0, 0 };
	/*		#...
			#...
			#...
			#...	*/
	int x2[] = { 0, 1, 2, 2 };
	int y2[] = { 1, 1, 0, 1 };
	/*		.#..
			.#..
			##..
			....	*/
	int x3[] = { 0, 1, 1, 2 };
	int y3[] = { 1, 0, 1, 0 };
	/*		.#..
			##..
			#...
			....	*/
	int x4[] = { 0, 0, 1, 2 };
	int y4[] = { 0, 1, 0, 0 };
	/*		##..
			#...
			#...
			....	*/
	int x5[] = { 0, 0, 1, 1 };
	int y5[] = { 1, 2, 0, 1 };
	/*		.##.
			##..
			....
			....	*/

	lst = 0;
	lstadd(&lst, lstnew(x4, y4, 'A'));
	lstadd(&lst, lstnew(x5, y5, 'B'));
	lstadd(&lst, lstnew(x2, y2, 'C'));
	lstadd(&lst, lstnew(x5, y5, 'D'));
	lstadd(&lst, lstnew(x1, y1, 'E'));
	lstshow(lst);
	
	size = 4;
	matrix = create_matrix(size);
	int x = 0;
	int y = 0;
	
	while (lst)
	{
		put_to_matrix(lst, matrix, size, x, y);
		lst = lst->next;
	}
	
	show_matrix(matrix, size);
	return (0);
}
