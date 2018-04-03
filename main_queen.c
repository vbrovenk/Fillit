/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_queen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:55:34 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/02 12:55:35 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_attacked(int row, int col, int board[4][4])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		if (board[row][y])
			return (1);
		y++;
	}
	x = 0;
	while (x < 4)
	{
		if (board[x][col])
			return (1);
		x++;
	}
	x = row;
	y = col;
	while (y >= 0 && x >= 0)
	{
		if (board[x][y])
			return (1);
		y--;
		x--;
	}
	x = row;
	y = col;
	while (y >= 0 && x >= 0)
	{
		if (board[x][y])
			return (1);
		x--;
		y++;
	}

	return (0);
}

int n_queens(int board[4][4], int N)
{
	int i;
	int j;

	if (N == 0)
		return (1);
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (is_attacked(i, j, board))
			{
				j++;
				continue ;
			}
			board[i][j] = 1;
			if (n_queens(board, N - 1))
				return (1);
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int main()
{
	int board[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	
	// if (is_attacked(1, 1, board))

	// 	printf("Attacked");
	// else
	// 	printf("NOT");
	if (n_queens(board, 4))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf(" %c ", board[i][j] + 48);
			}
			printf("\n");
		}
	}

	return (0);
}
