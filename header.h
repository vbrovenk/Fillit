/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:53:15 by vbrovenk          #+#    #+#             */
/*   Updated: 2018/04/03 15:57:52 by vbrovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct	s_tetro
{
	int				x[4];
	int				y[4];
	char			symbol;
	struct s_tetro	*next;
}				t_tetro;

typedef	struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

t_tetro			*lstnew(int *x, int *y, char c);
void			lstadd(t_tetro **lst, t_tetro *new);
void			lstclear(t_tetro **lst);
void			show_matrix(char **m, int size);
char			**create_matrix(int size);
int				put_to_matrix(t_tetro *elem, char **m, int size, t_coord cell);
char			**create_matrix(int size);
void			clear(char **m, int size);
void			show_matrix(char **m, int size);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_error(void);
void			ft_usage(void);
void			ft_bzero(char *s, int n);
int				count_hashes(char *s);
int				connected_hashes(char *buf);
char			**line_to_arr(char *buf);
void			clean_neighbours(char **figure, int i, int j, int *hashes);
void			file_to_list(int fd, t_tetro **lst);

#endif
