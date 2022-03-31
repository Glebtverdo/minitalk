/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:45:18 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/10 11:17:38 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t			size;
	size_t			little_len;	
	char			*the_same_letter;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big);
	the_same_letter = ft_strchr(big, little[0]);
	size = the_same_letter - big;
	if (size + little_len <= len)
	{
		if (!(ft_strncmp(the_same_letter, little, little_len)))
			return (the_same_letter);
		else
			return (ft_strnstr(&the_same_letter[1], little, (len - size)));
	}
	return (NULL);
}
