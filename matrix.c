/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:30:13 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/09 19:30:15 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	ft_bzero(char *s, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		s[i] = '\0';
}

void	show_matrix(char **m, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(m[i][j]);
		ft_putchar('\n');
	}
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
	while (5 * i + j < 20)
	{
		if (buf[5 * i + j] == '\n')
		{
			i++;
			j = 0;
			continue ;
		}
		f[i][j] = buf[5 * i + j];
		j++;
	}
	return (f);
}
