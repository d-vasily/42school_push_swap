/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:34:32 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 18:37:37 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pass_way(t_stack *a, t_stack *b, long *d)
{
	long int	n[4];

	n[0] = d[0] * (d[5] < 2) + d[1] * (d[5] > 1);
	n[1] = d[2] * (d[5] % 3 == 0) + d[3] * (d[5] % 3 != 0);
	n[2] = n[0] * (n[0] <= n[1]) + n[1] * (n[1] < n[0]);
	n[2] *= (d[5] % 2 == 0);
	n[0] -= n[2];
	n[1] -= n[2];
	while (d[5] < 2 && n[0]-- > 0)
		stack_operation(a, b, "rb", 1);
	while (d[5] >= 2 && n[0]-- > 0)
		stack_operation(a, b, "rrb", 1);
	while ((d[5] % 3 == 0) && n[1]-- > 0)
		stack_operation(b, a, "ra", 1);
	while (d[5] % 3 && n[1]-- > 0)
		stack_operation(b, a, "rra", 1);
	while (d[5] == 0 && n[2]-- > 0)
		stack_operation(b, a, "rr", 1);
	while (d[5] == 2 && n[2]-- > 0)
		stack_operation(b, a, "rrr", 1);
	stack_operation(b, a, "pa", 1);
}

// n[i]:			n[0] - 1 move, n[1] - 2 move, n[2] - 1 general move, 
// 					n[3] - 2 general move 
// ways[5]/d[5]:	0 - up up, 1 - up down, 2 - down down, 3 - down up
// ways[i]/d[i]:	0 - b up, 1 - b down, 2 - a up, 3 - a down, 4 - sum distance

void	ft_choose_way(long int *ways)
{
	long int	way_sum[4];
	int			i;

	way_sum[0] = (ways[0] > ways[2]);
	way_sum[0] = ways[0] * way_sum[0] + ways[2] * (!way_sum[0]);
	way_sum[1] = ways[0] + ways[3];
	way_sum[2] = (ways[1] > ways[3]);
	way_sum[2] = ways[1] * way_sum[2] + ways[3] * (!way_sum[2]);
	way_sum[3] = ways[1] + ways[2];
	ways[4] = way_sum[0];
	ways[5] = 0;
	i = 0;
	while (i++ < 3)
	{
		if (way_sum[i] < ways[4])
		{
			ways[4] = way_sum[i];
			ways[5] = i;
		}
	}
	if (ways[0] == 0 && ways[1] == 0 && ways[5] == 0)
		ways[5] = 3;
}

void	ft_count_way(long int *arr, int num, long int st1_size, t_stack *st2)
{
	t_node	*first;
	t_node	*last;
	int		i;

	arr[2] = 0;
	last = st2->last;
	first = st2->first;
	while (first)
	{
		i = ((first->num <= last->num)
				&& (num < first->num || num > last->num));
		if (i || (num < first->num && num > last->num))
			break ;
		arr[2]++;
		first = first->next;
		last = last->next;
		if (last == 0)
			last = st2->first;
	}
	arr[1] = (st1_size - arr[0]) * (arr[0] != 0);
	arr[3] = (st2->size - arr[2]) * (arr[2] != 0);
	ft_choose_way(arr);
}

void	ft_do_iteration(t_stack *a, t_stack *b, \
		long int *min_way, long int *tmp)
{
	long int	i;
	t_node		*node_start;
	t_node		*node_end;

	i = 1;
	min_way[0] = 0;
	ft_count_way(min_way, a->first->num, a->size, b);
	node_start = a->first;
	node_end = a->last;
	while (i <= a->size / 2 && i < b->size / 2)
	{
		node_start = node_start->next;
		tmp[0] = i;
		ft_count_way(tmp, node_start->num, a->size, b);
		ft_swap_arr(min_way, tmp);
		tmp[0] = a->size - i++;
		ft_count_way(tmp, node_end->num, a->size, b);
		ft_swap_arr(min_way, tmp);
		node_end = node_end->prev;
	}
	ft_pass_way(a, b, min_way);
}
