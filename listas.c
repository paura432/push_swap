/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:26:09 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:15:23 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*lstlast(stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(stack **lst, stack *new)
{
	stack	*new1;

	new1 = lstnew(new->content, new->index);
	if (*lst)
		lstlast(*lst)->next = new1;
	else
		*lst = new;
}

void	lstadd_front(stack **lst, stack *new)
{
	stack	*new1;

	new1 = lstnew(new->content, new->index);
	new1->next = *lst;
	*lst = new1;
}

stack	*lstnew(int content, int index)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if (!new)
		return (0);
	new->index = index;
	new->content = content;
	new->next = 0;
	return (new);
}

int	lstsize(stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
