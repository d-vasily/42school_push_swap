/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:13:46 by eelroy            #+#    #+#             */
/*   Updated: 2022/02/23 15:34:16 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_atoi(const char *str, int *res)
{
	int				i;
	int				sign;

	*res = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*res = *res * 10 + (str[i] - '0') * sign;
		i++;
		if ((*res < 0 && sign > 0) || (*res > 0 && sign < 0))
			return (NULL);
	}
	if (str[i] != 0)
		return (NULL);
	return (res);
}
