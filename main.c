/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:21:03 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/09 19:21:07 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init(t_tetro **lst, t_coord *cell)
{
	*lst = 0;
	cell->x = 0;
	cell->y = 0;
}

int			main(int args, char **argv)
{
	int			fd;
	t_tetro		*lst;
	char		**matrix;
	int			size;
	t_coord		cell;

	if (args == 2)
	{
		fd = open(argv[1], O_RDONLY);
		init(&lst, &cell);
		file_to_list(fd, &lst);
		size = 2;
		matrix = create_matrix(size);
		while (!put_to_matrix(lst, matrix, size, cell))
		{
			clear(matrix, size);
			size++;
			matrix = create_matrix(size);
		}
		show_matrix(matrix, size);
		lstclear(&lst);
	}
	else
		ft_usage();
	return (0);
}
