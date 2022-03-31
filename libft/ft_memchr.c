/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:42:52 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:44:24 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(void *arr, int c, size_t n)
{
	unsigned char	*new_arr;
	unsigned char	new_c;

	new_arr = arr;
	new_c = c;
	while (n > 0)
	{
		if (*new_arr == new_c)
			return (arr);
		new_arr++;
		arr++;
		n--;
	}
	return (NULL);
}
