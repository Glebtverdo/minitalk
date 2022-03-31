/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:42:21 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/10 10:42:34 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_skip_spaces(const char *str, size_t i)
{
	while ((str[i] == 32) | ((str[i] >= 9) & (str[i] <= 13)))
	{
		i++;
	}
	return (i);
}

static int	ft_check_long(size_t counter, int minus, size_t result)
{
	if (counter > 19)
	{
		if (minus == -1)
			return (0);
		else
			return (-1);
	}
	return (result * minus);
}

int	ft_atoi(const char *str)
{
	size_t					i;
	unsigned long long int	result;
	int						minus;
	size_t					counter;

	result = 0;
	i = 0;
	minus = 1;
	counter = 0;
	i = ft_skip_spaces(str, i);
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		counter++;
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_check_long(counter, minus, result));
}
