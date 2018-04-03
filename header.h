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

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_tetro
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	char 		symbol;
}				t_tetro;

#endif
