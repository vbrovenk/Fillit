/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:22:54 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/09 19:22:55 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	ft_usage(void)
{
	ft_putstr("usage: ./fillit sample\n");
	exit(1);
}

void	clear(char **m, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		free(m[i]);
	free(m);
}
