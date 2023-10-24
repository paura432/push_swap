/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by pramos            #+#    #+#             */
/*   Updated: 2023/10/24 23:26:52 by pramos           ###   ########.fr       */
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
				return (free_stack(stack_a), 0);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (1);
}

int	serch_wrong(char **spl_arr)
{
	int	j;
	int	i;
	int spl;

	j = 0;
	while (spl_arr[j])
	{
		i = 0;
		spl = ft_atoi(spl_arr[j]);
		printf("%i\n", spl);
		if (spl > 2147483647 && spl < -2147483648)
			return (0);
		while (spl_arr[j][i] != '\0')
		{
			if (!ft_atoi(&spl_arr[j][i]))
				return (0);
			i++;
		}
		j++;
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
			if	(!serch_wrong(spl_arr))
				return (free_stack(stack_a), ft_free(spl_arr, j + 1), 0);
			if (!ft_atoi(spl_arr[j]))
				return (free_stack(stack_a), ft_free(spl_arr, j + 1), 0);
			if (spl_arr[j][0] == '0' && spl_arr[j][1] != '0')
				return (free_stack(stack_a), ft_free(spl_arr, j + 1), 1);

			j++;
		}
		ft_free(spl_arr, j);
		i++;
	}
	if (!check_doubles(stack_a))
		return (0);
	return (1);
}
