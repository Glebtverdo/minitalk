/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:42:24 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:44:34 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *destination, size_t len)
{
	size_t			i;
	unsigned char	*new;

	new = destination;
	i = 0;
	while (i < len)
	{
		*new = 0;
		new++;
		i++;
	}
	return (destination);
}
