/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:08:57 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 18:53:59 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	long int		size;
	struct s_node	*first;
	struct s_node	*last;
}	t_stack;

t_stack	*stack_create(void);
int		stack_add(t_stack *stack, char side, int num, t_node *node);
void	stack_operation(t_stack *stack, t_stack *stack_2,
			char *comand, int num_print);
void	ft_do_iteration(t_stack *a, t_stack *b,
			long int *min_way, long int *tmp);
int		ft_input(t_stack *a, int argc, char **argv);
void	ft_output(int ok, t_stack *a, t_stack *b);
void	ft_sort(t_stack *a, t_stack *b, long int *data, long int *tmp);
void	ft_swap_arr(long int *arr1, long int *arr2);

#endif
