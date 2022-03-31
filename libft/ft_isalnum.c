/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:42:30 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:44:48 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int n)
{
	return ((n >= 65 && n <= 90) || (n >= 97 && n <= 122) \
	|| (n >= 48 && n <= 57));
}