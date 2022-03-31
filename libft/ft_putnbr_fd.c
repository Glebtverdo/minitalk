/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:41:50 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/22 17:15:25 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_main_func(long int dev, long int new_n, int size, int fd)
{
	while (dev > 0)
	{
		ft_putchar_fd(new_n / dev + 48, fd);
		new_n = new_n % dev;
		dev /= 10;
		size++;
	}
}

void	ft_putnbr_fd(long int n, int fd)
{
	long int		dev;
	long int		new_n;
	int				size;

	dev = 1;
	size = 1;
	new_n = n;
	if (new_n < 0)
	{
		size++;
		new_n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (new_n >= dev * 10)
	{
		dev *= 10;
		size++;
	}
	ft_main_func(dev, new_n, size, fd);
}
