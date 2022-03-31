/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:41:36 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:44:18 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	*free_all(char **new, long long int iii, long long int max)
{
	free(new[max]);
	while (iii >= 0)
	{
		free(new[iii]);
		iii--;
	}
	free(new);
	return (NULL);
}	

static int	skip_c(long long int i, char const *s, char c)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static long long int	arr_count_counter(const char *s, \
long long int i, char c)
{
	long long int	arr_count;

	if (s[i] != c && s[i])
		arr_count = 1;
	else
		arr_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i = skip_c(i, s, c);
			if (s[i] != c && s[i] != '\0')
				arr_count++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (arr_count);
}

static char	**ft_main_logic(long long int arr_count, \
			const char *s, char c, char **new)
{
	long long int	ii;
	long long int	iii;
	long long int	i;

	ii = 0;
	iii = 0;
	i = skip_c(0, s, c);
	while (arr_count >= iii)
	{
		ii = 0;
		while (s[i] != c && s[i] != '\0')
		{	
			ii++;
			i++;
		}
		new[iii] = malloc(sizeof(char) * ii);
		if (new[iii] == NULL)
			return (free_all(new, iii, arr_count));
		ft_strlcpy(new[iii], &s[i - ii], ii + 1);
		iii++;
		i = skip_c(i, s, c);
	}
	return (new);
}

char	**ft_split(char const *s, char c)
{
	long long int	i;
	long long int	arr_count;
	char			**new;

	if (s == NULL)
		return (NULL);
	i = 0;
	i = skip_c(i, s, c);
	arr_count = arr_count_counter(s, i, c);
	new = (char **)malloc(sizeof(char *) * (arr_count + 1));
	if (new == NULL)
		return (NULL);
	new[arr_count--] = NULL;
	new = ft_main_logic(arr_count, s, c, new);
	return (new);
}
