/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:45:21 by vearleen          #+#    #+#             */
/*   Updated: 2021/10/08 20:45:33 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(char *string, int symbol)
{
	long long int	i;

	i = 0;
	i = ft_strlen(string);
	if (symbol > 255)
		symbol -= 256;
	while (i >= 0)
	{
		if (string[i] == symbol)
			return (&string[i]);
		i--;
	}
	return (NULL);
}
