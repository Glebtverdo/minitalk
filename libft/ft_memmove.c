/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:44:50 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:54 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	size_t			i;
	unsigned char	*new_dest;
	unsigned char	*new_src;

	i = 0;
	new_dest = dest;
	new_src = src;
	if (new_dest > new_src)
	{
		while (len > 0)
		{
			new_dest[len - 1] = new_src[len - 1];
			len--;
		}
	}
	else
	{
		while ((new_dest != NULL || new_src != NULL) && (i < len))
		{
			*new_dest++ = *new_src++;
			i++;
		}
	}
	return (dest);
}
