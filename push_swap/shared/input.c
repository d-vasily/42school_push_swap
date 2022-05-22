/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:42 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 18:31:29 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_handle_num(t_stack *a, char *s, int *ok, int check_sort)
{
	int		num;
	t_node	*node;

	if (!ft_atoi(s, &num))
		*ok = 0;
	node = a->first;
	if (*ok && a->last && num < a->last->num)
		*ok = 2;
	if (*ok && !stack_add(a, 1, num, 0))
		*ok = 0;
	while (*ok && node && node->next && *ok > 0)
	{
		if (node->num == num)
			*ok = 0;
		node = node->next;
	}
	node = a->first;
	while (*ok != 0 && *ok != 2 && check_sort && node)
	{
		if (node->next && node->num > node->next->num)
			*ok = 2;
		node = node->next;
	}
}

int	ft_input(t_stack *a, int argc, char **argv)
{
	char	**s;
	int		j;
	int		i;
	int		ok;

	ok = 1;
	i = 1;
	while (ok > 0 && i < argc)
	{
		s = ft_split(argv[i++], ' ');
		if (!s)
			return (0);
		j = 0;
		while (ok > 0 && s[j++])
			ft_handle_num(a, s[j - 1], &ok, (i == argc && !s[j]));
		j = 0;
		while (s[j])
			free(s[j++]);
		free(s);
	}
	return (ok);
}

void	ft_swap_arr(long int *arr1, long int *arr2)
{
	int	i;

	if (arr1[4] < arr2[4])
		return ;
	i = -1;
	while (++i < 6)
		arr1[i] = arr2[i];
}
