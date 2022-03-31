/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:40:35 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:40:38 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	long long int	s1_len;
	char			*new;
	char			*new_set;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	new_set = (char *)set;
	while (s1[i] && (ft_strchr(new_set, s1[i])))
		i++;
	s1_len = ft_strlen(&s1[i]) - 1;
	while (s1[s1_len + i] && (ft_strchr(new_set, s1[s1_len + i])) \
		&& s1_len > -1)
		s1_len--;
	new = malloc(sizeof(char) * (s1_len + 2));
	if (new == NULL)
		return (NULL);
	new[s1_len + 1] = '\0';
	while (s1_len >= 0)
	{
		new[s1_len] = s1[i + s1_len];
		s1_len--;
	}
	return (new);
}
