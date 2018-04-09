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
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while(s[i])
		write(1, &s[++i], 1);
}

void	ft_error(void)
{
	// printf("error\n");
	//ft_putstr("error\n");
	exit(1);
}

void	ft_bzero(char *s, int n)
{
	int		i;

	i = -1;
	while(++i < n)
		s[i] = '\0';
}

int		count_hashes(char *s) /* also checks valid symbols */ 
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (s[5*i + j] == '#')
				count++;
			if (s[5*i + j] != '.' && s[5*i + j] != '#')
			{
				printf("unknown symbol\n");
				ft_error();
			}
			j++;
		}
		if (s[5 * i + j] != '\n')
		{
			printf("without end of line\n");
			ft_error();
		}
		i++;
	}
	return (count);
}

void	replace_coordinats(int *x, int *y)
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

t_tetro	*elem_creating(char *buf, char sym)
{
	int			n;
	int			i;
	int			j;
	int			x[4];
	int			y[4];

	i = -1;
	while (++i < 4)
	{
		x[i] = -1;
		y[i] = -1;
	}
	i = 0;
	j = 0;
	n = 0;
	while (5 * i + j < 20)
	{
		if (buf[5*i + j] == '\n')
		{
			i++;
			j = 0;
			continue ;
		}
		if (buf[5 * i + j] == '#')
		{
			x[n] = i;
			y[n] = j;
			n++;
		}
		j++;
	}
	replace_coordinats(x, y);
	return (lstnew(x, y, sym));
}

char	**line_to_arr(char *buf)
{
	int		i;
	int		j;
	char	**f;

	i = -1;
	f = (char**)malloc(sizeof(char*) * 4);
	while (++i < 4)
		f[i] = (char*)malloc(sizeof(char) * 4);
	i = 0;
	j = 0;
	while(5 * i + j < 20)
	{
		if (buf[5*i + j] == '\n')
		{
			i++;
			j = 0;
			continue ;
		}
		f[i][j] = buf[5*i + j];
		j++;
	}
	return (f);
}

void	clean_neighbours(char **figure, int i, int j, int *hashes)
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

int		connected_hashes(char *buf)
{
	char	**f;
	int		i;
	int		j;
	int		hashes;

	f = line_to_arr(buf);
	i = -1;
	while(++i < 4)
	{
		j = -1;
		while(++j < 4)
		{
			if (f[i][j] == '#')
			{
				hashes = 0;
				clean_neighbours(f, i, j, &hashes);
				if (hashes != 4)
					return (0);
			}
		}
	}
	return (1);
}

void	file_to_list(int fd, t_tetro **lst)
{
	char	buf[20];
	char	skip[1];
	char	sym;

	if (fd == -1)
	{
		printf("unknown file\n");
		ft_error();
	}
	sym = 'A' - 1;
	while (1)
	{
		ft_bzero(buf, 20);
		read(fd, buf, 20);
		if (skip[0] == '\n' && buf[0] == '\0')
		{
			printf("unwanted end of line\n");
			ft_error();
		}
		//printf("%s\n", buf);
		ft_bzero(skip, 1);
		read(fd, skip, 1);
		//printf("%i\n", count_hashes(buf));
		if (count_hashes(buf) != 4)
		{
			printf("there are not 4 hashes\n");
			ft_error();
		}

		if (connected_hashes(buf) != 1)
		{
			printf("hashes are not connected\n");
			ft_error();
		}
		else
		{
			// printf("OK\n");
			lstadd(lst, elem_creating(buf, ++sym));
		}
		//printf("%i\n", skip[0]);
		if (skip[0] == '\0')
			break ;
	}
}

int		main(int args, char **argv)
{
	/* now you may gcc valid.c list.c algo.c */
	int		fd;
	t_tetro	*lst;
	char	**matrix;
	int		size;

	if (args == 2)
	{
		fd = open(argv[1], O_RDONLY);
		lst = 0;
		file_to_list(fd, &lst);
		lstshow(lst);
		size = 2;
		matrix = create_matrix(size);
		while (!put_to_matrix(lst, matrix, size, 0, 0))
		{
			printf("too small square\n");
			size++;
			matrix = create_matrix(size);
			show_matrix(matrix, size);
		}
	}
	else
	{
		printf("without file\n");
		ft_error();
	}
	return (0);
}
