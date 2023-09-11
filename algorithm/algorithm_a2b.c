/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_a2b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:03:13 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:44:01 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_sort(stack **stack_b, stack **stack_a, int i, int division)
{
	int	tope;
	int	div;

	div = check_divisions(*stack_a, i);
	tope = division;
	division = division - div;
	if ((stack_biggestindex(*stack_a) == (*stack_a)->index  || stack_biggestindex(*stack_a) - 1 == (*stack_a)->index || stack_biggestindex(*stack_a) - 2 == (*stack_a)->index))
		ra(stack_a);
	else if (division - div == div * i)
		pb(stack_a ,stack_b);
	else if (division > (*stack_a)->index)
	{
		pb(stack_a ,stack_b);
		rb(stack_b);
	}
	else if (tope > (*stack_a)->index)
		pb(stack_a ,stack_b);
	else
		ra(stack_a);
}

int	serch_num_a2b(stack **stack_a, stack **stack_b, int division)
{
	stack *stack_aux;
	int i;

	i = 0;
	if(stack_b == NULL)
		return(i);
	stack_aux = (*stack_a);
	while(stack_aux == NULL)
	{
		if(stack_aux->index <= division)
		{
			i = 1;
			break;
		}
		stack_aux = stack_aux->next;
	}
	return(i);
}

void    sort_a2b(stack **stack_a, stack **stack_b, int division, int i)
{
	stack *stack_aux;
	int div;
	int size;
	int j;
	
	div = division;
	division = div * 2;
	while((*stack_a)->next->next->next != 0)
	{
		j = 0;
		size = lstsize(*stack_a);
		stack_aux = *stack_a;
		while(j < size)
		{
			first_sort(stack_b, stack_a, i, division);
			if(serch_num_a2b(stack_a, stack_b, division) == 1)
				break;
			stack_aux = stack_aux->next;
			j++;
		}
		division = division + (div * 2);
	}
}