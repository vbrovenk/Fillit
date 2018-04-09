/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:37:23 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/09 19:37:26 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		count_hashes(char *s)
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
			if (s[5 * i + j] == '#')
				count++;
			if (s[5 * i + j] != '.' && s[5 * i + j] != '#')
				ft_error();
			j++;
		}
		if (s[5 * i + j] != '\n')
			ft_error();
		i++;
	}
	return (count);
}

int		connected_hashes(char *buf)
{
	char	**f;
	int		i;
	int		j;
	int		hashes;

	f = line_to_arr(buf);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
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
	clear(f, 4);
	return (1);
}
