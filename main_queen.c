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
#define N 4

void print_solution(int board[N][N])
{
	int x;
	int y;

	x = 0;
	while (x < N)
	{
		y = 0;
		while (y < N)
		{
			printf(" %d ", board[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

int is_safe(int board[N][N], int row, int col)
{
	int x;
	int y;

	y = 0;
	while (y < col)
	{
		if (board[row][y])
			return (0);
		y++;
	}
	x = row;
	y = col;
	while (x >= 0 && y >= 0)
	{
		if (board[x][y])
			return (0);
		x--;
		y--;
	}
	x = row;
	y = col;
	while (x < N && y >= 0)
	{
		if (board[x][y])
			return (0);
		x++;
		y--;
	}
	return (1);
}

int solveNQ(int board[N][N], int col)
{
	int row;

	if (col >= N)
		return (1);
	row = 0;
	while (row < N)
	{
		if (is_safe(board, row, col))
		{
			board[row][col] = 1;
			if (solveNQ(board, col + 1))
				return (1);
			board[row][col] = 0;
		}
		row++;
	}
	return (0);
}

int solve()
{
	int board[N][N] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	if (solveNQ(board, 0) == 0)
		return (0);
	print_solution(board);
	return (1);
}

int main()
{
	int isSolved = solve();
	return (0);
}
