/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:04:29 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/26 11:40:33 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_a_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (b->size > 0)
		return (0);
	node = a->first;
	while (node->next)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_exec(t_stack *a, t_stack *b, char *s)
{
	int		res;
	t_stack	*tmp;

	res = 1;
	if (ft_strchr("psr", s[0]) && ft_strchr("ab", s[1]) && s[2] == '\n')
		res *= 0;
	if (s[0] == 'r' && s[1] == 'r' && ft_strchr("rab", s[2]))
		res *= 0;
	res *= ft_strncmp(s, "rr\n", 3) * ft_strncmp(s, "ss\n", 3);
	if (res)
		ft_putstr_fd("Error\n", 1);
	if (res)
		exit(0);
	tmp = a;
	if (s[1] == 'b' || s[2] == 'b')
		a = b;
	if (a == b)
		b = tmp;
	if (s[2] == '\n')
		s[2] = 0;
	if (s[1] == 's')
		stack_operation(b, a, "sa", 0);
	stack_operation(a, b, s, 0);
	if (s[2] == 0)
		s[2] = '\n';
}

void	ft_checker(t_stack *a, t_stack *b)
{
	char	s[3];
	int		rd;
	int		i;

	i = 0;
	rd = read(0, s, 3);
	if (ft_check_a_b(a, b) && rd > 0)
		rd = -1;
	while (rd > 0)
	{
		rd -= (i > 3 && a->size + b->size <= 3) * 10;
		rd -= (i++ > 12 && a->size + b->size <= 5) * 10;
		if (rd > 0)
			ft_exec(a, b, s);
		if (rd > 0 && s[2] != '\n' && (!(read(0, s, 1)) || s[0] != '\n'))
			rd = -1;
		if (rd > 0)
			rd = read(0, s, 3);
	}
	if (rd < 0)
		ft_putstr_fd("Error\n", 1);
	else if (ft_check_a_b(a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ok;

	if (argc < 2)
		return (0);
	a = stack_create();
	b = stack_create();
	if (!a || !b)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	ok = ft_input(a, argc, argv);
	if (ok == 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	ft_checker(a, b);
	exit(0);
	return (0);
}
