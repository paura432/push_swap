/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:35:21 by pramos            #+#    #+#             */
/*   Updated: 2023/10/26 19:00:19 by pramos           ###   ########.fr       */
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
	int		j;
	int		i;

	j = 0;
	while (spl_arr[j])
	{
		i = 0;
		if(ft_strlen(spl_arr[j]) > 11)
			return(0);
		if(ft_strchr(spl_arr[j], '-') && ft_atoi(spl_arr[j]) > 0)
			return(0);
		if(!ft_strchr(spl_arr[j], '-') && ft_atoi(spl_arr[j]) < 0)
			return(0);
		while (spl_arr[j][i] != '\0')
		{
			if (!ft_atoi(&spl_arr[j][i]) && spl_arr[j][i] != '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int serch_spaceonly(char **argv)
{
	int i;
	int j;

	j = 1;
	while(argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] != ' ')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_errors(char **argv)
{
	char	**spl_arr;
	int		i;
	int		j;

	i = 1;
	if(!serch_spaceonly(argv))
		return(0);
	while (argv[i])
	{
		spl_arr = ft_split(argv[i], ' ');
		j = 0;
		while (spl_arr[j])
		{
			if(spl_arr[j][0] == '0')
				return(1);
			if	(!serch_wrong(spl_arr))
				return (ft_free(spl_arr, j + 1), 0);
			if (!ft_atoi(spl_arr[j]))
				return (ft_free(spl_arr, j + 1), 0);
			j++;
		}
		ft_free(spl_arr, j);
		i++;
	}
	return (1);
}
