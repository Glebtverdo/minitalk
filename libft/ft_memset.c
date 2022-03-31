/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:44:53 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:51 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	size_t			i;
	unsigned char	*new;

	new = destination;
	i = 0;
	while (i < len)
	{
		*new = c;
		new++;
		i++;
	}
	return (destination);
}
