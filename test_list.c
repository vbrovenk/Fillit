/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:12:58 by osamoile          #+#    #+#             */
/*   Updated: 2018/04/03 16:13:24 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		main(void)
{
	t_tetro *lst;

	int x1[] = { 0, 0, 1, 2 };
	int y1[] = { 0, 1, 0, 0 };
	int x2[] = { 0, 0, 0, 0 };
	int y2[] = { 0, 1, 2, 3 };
	int x3[] = { 0, 1, 1, 2 };
	int y3[] = { 1, 0, 1, 0 };

	lst = 0;
	lstadd(&lst, lstnew(x1, y1, 'A'));
	lstadd(&lst, lstnew(x2, y2, 'B'));
	lstadd(&lst, lstnew(x3, y3, 'C'));
	lstdelone(&(lst->next));
	// lstclear(&lst);
	lstshow(lst);
	if (lst == 0)
		printf("clear\n");
	// system ("leaks a.out");
	return (0);
}
