/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:43:41 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:43:49 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_main_func(long int dev, long int new_n, int size, char *new)
{
	while (dev > 0)
	{
		new[size] = new_n / dev + 48;
		new_n = new_n % dev;
		dev /= 10;
		size++;
	}
	new[size] = '\0';
	return (new);
}

static int	minus_new(char *new, int new_n)
{
	if (new_n >= 0)
		return (0);
	else
	{
		*new = '-';
		return (1);
	}
}

char	*ft_itoa(int n)
{
	long int		dev;
	long int		new_n;
	int				size;
	char			*new;

	dev = 1;
	size = 1;
	new_n = n;
	if (new_n < 0)
	{
		size++;
		new_n *= -1;
	}
	while (new_n >= dev * 10)
	{
		dev *= 10;
		size++;
	}
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	size = minus_new(&new[0], n);
	new = ft_main_func(dev, new_n, size, new);
	return (new);
}
