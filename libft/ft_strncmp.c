/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:45:14 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:35 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	first_str;
	unsigned char	second_str;

	i = 0;
	while (i < n)
	{
		first_str = str1[i];
		second_str = str2[i];
		if ((first_str != second_str) | (first_str == '\0') \
				| (second_str == '\0'))
			return (first_str - second_str);
		i++;
	}
	return (0);
}
