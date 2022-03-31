/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:44:45 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:55 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t len)
{
	size_t				i;
	unsigned char		*new;
	unsigned const char	*new_source;

	if (source != NULL | destination != NULL)
	{
		new = destination;
		new_source = source;
		i = 0;
		while ((i < len))
		{
			*new = *new_source;
			new_source++;
			new++;
			i++;
		}
	}
	return (destination);
}
