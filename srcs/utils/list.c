/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:57:34 by cdionna           #+#    #+#             */
/*   Updated: 2021/05/11 18:17:20 by cdionna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

t_list	*ft_lstnew(int x, int y)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->x = x;
	new->y = y;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *list)
{
	t_list	*p;

	p = *lst;
	if (lst == NULL || p == NULL)
		*lst = list;
	else
	{
		while (p->next)
			p = p->next;
		p->next = list;
	}
}
