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

t_tetro		*lstnew(int *x, int *y, char c);
void		lstadd(t_tetro **lst, t_tetro *new);
void		lstclear(t_tetro **lst);
void		lstdelone(t_tetro **lst);
void		lstshow(t_tetro *lst); // trash

void		show_matrix(char **m, int size);
char		**create_matrix(int size);
int			put_to_matrix(t_tetro *elem, char **m, int size, int x, int y);

#endif
