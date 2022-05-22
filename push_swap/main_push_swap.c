/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:45:00 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 18:33:01 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_find_min_max(t_stack *a, int min_max)
{
	long int	i;
	long int	res_i;
	int			res_num;
	t_node		*node;

	res_i = 0;
	i = -1;
	node = a->first;
	if (node)
		res_num = node->num;
	while (node)
	{
		i++;
		if (!min_max && node->num < res_num)
			res_i = i;
		if (min_max && node->num > res_num)
			res_i = i;
		if (res_i == i)
			res_num = node->num;
		node = node->next;
	}
	return (res_i);
}

void	ft_rotate_a(t_stack *a, t_stack *b)
{
	int			r;
	char		*s;
	long int	min_i;

	min_i = ft_find_min_max(a, 0);
	s = "ra";
	r = min_i > (int)(a->size / 2);
	if (r)
		s = "rra";
	while (min_i > 0 && min_i < a->size)
	{
		stack_operation(a, b, s, 1);
		min_i += r - !r;
	}
}

void	ft_sort(t_stack *a, t_stack *b, long int *data, long int *tmp)
{
	int			max_i;

	max_i = ft_find_min_max(a, 1);
	if (a->size <= 3)
	{
		if (max_i == 0)
			stack_operation(a, b, "ra", 1);
		else if (max_i == 1)
			stack_operation(a, b, "rra", 1);
		if (a->first->num > a->first->next->num)
			stack_operation(a, b, "sa", 1);
		return ;
	}
	while (a->size > 2)
		stack_operation(b, a, "pb", 1);
	while (b->size > 0)
		ft_do_iteration(b, a, data, tmp);
	ft_rotate_a(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			ok;
	long int	*data;
	long int	*tmp;

	data = (long int *)malloc(sizeof(long int) * 6);
	tmp = (long int *)malloc(sizeof(long int) * 6);
	if (argc < 2)
		return (0);
	a = stack_create();
	b = stack_create();
	if (!tmp || !data || !a || !b)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	ok = ft_input(a, argc, argv);
	if (ok == 0)
		ft_putstr_fd("Error\n", 1);
	if (ok != 1 && ok != 0)
		ft_sort(a, b, data, tmp);
	exit(0);
	return (0);
}
