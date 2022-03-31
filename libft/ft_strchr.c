/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:44:56 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:49 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(char *string, int symbol)
{
	if (symbol > 255)
		symbol -= 256;
	while (*string)
	{
		if (*string == symbol)
			return (string);
		string++;
	}
	if (*string == symbol)
		return (string);
	return (NULL);
}
