/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:40:31 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:40 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_size_count(size_t s_len, unsigned int start, size_t len)
{
	size_t	size;

	if (start > s_len)
		size = 0;
	else if (start + len > s_len)
		size = s_len - start;
	else
		size = len;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size;
	size_t	i;
	char	*new;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	size = ft_size_count(s_len, start, len);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	new[size] = '\0';
	i = 0;
	while (size > i)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
