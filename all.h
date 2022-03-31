/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:24:54 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/22 17:14:12 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include <signal.h>
# include <zconf.h>
# include"./libft/libft.h"
# include <stdio.h>

typedef struct s_vars
{
	char				*print;
	int					client_message_char;
	int					signal_id;
	long int			signal_count;
	int					counter;
	int					minus;
	long long int		grade;
}	t_vars;

t_vars	*g_vars;
void	ft_error(char *error_message, int len);

#endif