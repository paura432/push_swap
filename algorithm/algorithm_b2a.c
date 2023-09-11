/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b2a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:49 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:40:13 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    second_sort(stack **stack_b, stack **stack_a)
{
	int i;
	
	i = 0;
	if(stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
		pa(stack_a, stack_b);
	else
	{
		rb(stack_b);
		i++;
	}
	return(i);
}

int    third_sort(stack **stack_b, stack **stack_a, int division)
{
	int i;

	i = 0;
	if(((*stack_b)->index > 0 && (*stack_b)->index == division) || (*stack_b)->index == lstlast(*stack_a)->index + 1)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		i++;
	}
	return(i);
}

int     serch_num_b2a(stack **stack_a, stack **stack_b, int division)
{
	stack *stack_aux;
	int i;

	i = 0;
	if(stack_b == NULL)
		return(i);
	stack_aux = (*stack_b);
	while(stack_aux->index >= division)
	{
		if(stack_aux->index + 1 == (*stack_a)->index || (*stack_b)->index == lstlast(*stack_a)->index + 1)
		{
			i = 1;
			break;
		}
		stack_aux = stack_aux->next;
	}
	return(i);
}

void    sort_chunk(stack **stack_a, stack **stack_b, int division)
{
	int i;

	i = 0;
	while(lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a) && stack_b && (*stack_b)->index >= division)
	{
		third_sort(stack_b, stack_a, division);
		i += second_sort(stack_b, stack_a);
		if(lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a) && serch_num_b2a(stack_a, stack_b, division) == 0 && division > 0)
			break;
	}
	while(i-- > 0 && division > 0)
	{
		rrb(stack_b, 0);
		if(stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
			pa(stack_a, stack_b);
		else if((division > 0 && (*stack_b)->index == division) || (*stack_b)->index == lstlast(*stack_a)->index + 1)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if(serch_num_b2a(stack_a, stack_b, division) == 1 && division > 0)
			sort_chunk(stack_a, stack_b, division);
	}
	if(stack_b && lstlast(*stack_a)->index + 1 == (*stack_a)->index)
		while(lstlast(*stack_a)->index + 1 == (*stack_a)->index)
			rra(stack_a, 0);
}

void    sort_b2a(stack **stack_a, stack **stack_b, int division, int i)
{
	int div;
	int j;

	div = division;
	division = division - (division - ((div / i) * i));
	while(lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a))
	{
		j = 0;
		if((*stack_b)->index >= division)
			while(stack_b && (*stack_a)->index > division)
				sort_chunk(stack_a, stack_b, division);
		else
		{
			while(j < (div / i) && (*stack_b)->index >= div / i && division != div)
			{
				rrb(stack_b, 0);
				if(stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
					pa(stack_a, stack_b);
				else if(division > 0 && (*stack_b)->index == lstlast(*stack_a)->index + 1)
				{
					pa(stack_a, stack_b);
					ra(stack_a);
				}
				j++;
			}
		}
		division = division - div / i;
	}
}