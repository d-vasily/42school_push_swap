/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:10:40 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 16:51:14 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*node_create(int num, t_node *prev, t_node *next, t_node *node)
{
	if (node)
		num = node->num;
	if (!node)
		node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->next = next;
	node->prev = prev;
	if (next)
		next->prev = node;
	if (prev)
		prev->next = node;
	node->num = num;
	return (node);
}

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->first = 0;
	stack->last = 0;
	return (stack);
}

int	stack_add(t_stack *stack, char side, int num, t_node *node)
{
	if (!side)
		node = node_create(num, 0, stack->first, node);
	else
		node = node_create(num, stack->last, 0, node);
	if (!node)
		return (0);
	stack->size++;
	if (side == 0)
		stack->first = node;
	else
		stack->last = node;
	if (stack->size == 1)
		stack->first = node;
	if (stack->size == 1)
		stack->last = node;
	return (1);
}

t_node	*stack_pop(t_stack *stack, char side)
{
	t_node	*node;

	stack->size--;
	node = stack->first;
	if (stack->size == 0)
	{
		stack->first = 0;
		stack->last = 0;
		return (node);
	}
	if (side == 0)
		stack->first = node->next;
	else
	{
		node = stack->last;
		stack->last = node->prev;
	}
	stack->first->prev = 0;
	stack->last->next = 0;
	return (node);
}

void	stack_operation(t_stack *a, t_stack *b, char *s, int flag)
{
	t_node	*node;
	int		tmp;

	ft_putendl_fd(s, 1, flag);
	tmp = (a->size < 2) * (s[0] != 'p') + (s[0] == 'p') * (b->size == 0);
	if (tmp)
		return ;
	if (s[0] == 's')
	{
		tmp = a->first->next->num;
		a->first->next->num = a->first->num;
		a->first->num = tmp;
	}
	if (s[0] == 'p')
		node = stack_pop(b, 0);
	if (s[0] == 'p')
		stack_add(a, 0, 0, node);
	if (s[0] == 'p' || s[0] == 's')
		return ;
	node = stack_pop(a, (s[2] != 0));
	stack_add(a, (s[2] == 0), 0, node);
	if (s[1] == 'a' || s[2] == 'a' || s[1] == 'b' || s[2] == 'b')
		return ;
	node = stack_pop(b, (s[2] != 0));
	stack_add(b, (s[2] == 0), 0, node);
}
