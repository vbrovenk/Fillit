/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:19:00 by osamoile          #+#    #+#             */
/*   Updated: 2018/04/04 18:19:02 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		replace_coordinats(int *x, int *y)
{
	while (x[0] * x[1] * x[2] * x[3] != 0)
	{
		x[0]--;
		x[1]--;
		x[2]--;
		x[3]--;
	}
	while (y[0] * y[1] * y[2] * y[3] != 0)
	{
		y[0]--;
		y[1]--;
		y[2]--;
		y[3]--;
	}
}

static void		init_var(int *i, int *j, int *n)
{
	*i = 0;
	*j = -1;
	*n = 0;
}

static t_tetro	*elem_creating(char *buf, char sym)
{
	int			n;
	int			i;
	int			j;
	int			x[4];
	int			y[4];

	if (sym == 'Z' + 1)
		ft_error();
	init_var(&i, &j, &n);
	while (5 * i + ++j < 20)
	{
		if (buf[5 * i + j] == '#')
		{
			x[n] = i;
			y[n] = j;
			n++;
		}
		if (buf[5 * i + j] == '\n')
		{
			i++;
			j = -1;
		}
	}
	replace_coordinats(x, y);
	return (lstnew(x, y, sym));
}

void			clean_neighbours(char **figure, int i, int j, int *hashes)
{
	if (figure[i][j] == '#')
	{
		figure[i][j] = '.';
		*hashes += 1;
		if (i != 0)
			clean_neighbours(figure, i - 1, j, hashes);
		if (j != 3)
			clean_neighbours(figure, i, j + 1, hashes);
		if (i != 3)
			clean_neighbours(figure, i + 1, j, hashes);
		if (j != 0)
			clean_neighbours(figure, i, j - 1, hashes);
	}
}

void			file_to_list(int fd, t_tetro **lst)
{
	char	buf[20];
	char	skip[1];
	char	sym;

	if (fd == -1)
		ft_error();
	sym = 'A' - 1;
	while (1)
	{
		ft_bzero(buf, 20);
		read(fd, buf, 20);
		if (skip[0] == '\n' && buf[0] == '\0')
			ft_error();
		ft_bzero(skip, 1);
		read(fd, skip, 1);
		if (count_hashes(buf) != 4 || connected_hashes(buf) != 1)
			ft_error();
		else
			lstadd(lst, elem_creating(buf, ++sym));
		if (skip[0] == '\0')
			break ;
	}
}
