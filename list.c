/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:01:39 by osamoile          #+#    #+#             */
/*   Updated: 2018/04/03 16:01:41 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_tetro		*lstnew(int *x, int *y, char c)
{
	t_tetro		*new;

	new = (t_tetro*)malloc(sizeof(t_tetro));
	int i = -1;
	while (++i < 4)
	{
		new->x[i] = x[i];
		new->y[i] = y[i];
	}
	new->symbol = c;
	new->next = 0;
	return (new);
}

void		lstadd(t_tetro **lst, t_tetro *new)
{
	t_tetro		*tmp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		lstclear(t_tetro **lst)
{
	while ((*lst)->next)
		lstclear(&(*lst)->next);
	lstdelone(lst);
}

void		lstdelone(t_tetro **lst)
{
	t_tetro	*buf;

	buf = (*lst)->next;
	free(*lst);
	*lst = 0;
	*lst = buf;
}