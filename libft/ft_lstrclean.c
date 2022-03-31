/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:42:37 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/20 21:42:40 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			buf = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = buf;
		}
	}
}
