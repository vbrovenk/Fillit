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

typedef	struct	s_tetro
{
	int				x[4];
	int				y[4];
	char			symbol;
	struct s_tetro	*next;
}				t_tetro;

t_tetro		*lstnew(int *x, int *y, char c);
void		lstadd(t_tetro *lst, int *x, int *y, char c);

#endif
