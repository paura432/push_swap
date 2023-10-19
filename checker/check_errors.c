/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by pramos            #+#    #+#             */
/*   Updated: 2023/09/12 17:51:07 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_doubles(t_stack *stack_a)
{
	t_stack	*p1;
	t_stack	*p2;

	p1 = stack_a;
	while (p1 != 0)
	{
		p2 = p1->next;
		while (p2 != 0)
		{
			if (p1->content == p2->content)
				return (0);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (1);
}

int	check_errors(char **argv, t_stack *stack_a)
{
	char	**spl_arr;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		spl_arr = ft_split(argv[i], ' ');
		j = 0;
		while (spl_arr[j])
		{
			if (spl_arr[j][0] == '0' && spl_arr[j][1] != '0')
				return (1);
			if (!ft_atoi(spl_arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_doubles(stack_a))
		return (0);
	free (spl_arr);
	return (1);
}
