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
	ft_putstr("error\n");
	exit(1);
}

void	ft_bzero(char *s, int n)
{
	int		i;

	i = -1;
	while(++i < n)
		s[i] = '\0';
}

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
			if (s[5*i + j] == '#')
				count++;
			if (s[5*i + j] != '.' && s[5*i + j] != '#')
				ft_error();
			j++;
		}
		if (s[5*i + j] != '\n')
			ft_error();
		i++;
	}
	return (count);
}

void	file_to_list(int fd)
{

	char	buf[20];
	char	skip[1];

	if (fd == -1)
		ft_error();
	while (1)
	{
		ft_bzero(buf, 20);
		read(fd, buf, 20);
		if (skip[0] == '\n' && buf[0] == '\0')
			ft_error();
		//printf("%s\n", buf);
		ft_bzero(skip, 1);
		read(fd, skip, 1);
		printf("%i\n", count_hashes(buf));
		if (count_hashes(buf) != 4)
			ft_error();
		//printf("%i\n", skip[0]);
		if (skip[0] == '\0')
			break ;
	}
	printf("OK\n");
}

int		main(int args, char **argv)
{

	int		fd;
	if (args == 2)
	{
		//printf("%s\n", argv[1]);
		fd = open(argv[1], fd);
		file_to_list(fd);
	
	}
	else
		ft_error();


	return (0);
}
