/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:56:18 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/22 17:35:01 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

void	ft_lines(void)
{
	if (g_vars->signal_id > 0 && g_vars->counter == 17)
	{
		g_vars->client_message_char *= g_vars->minus;
		g_vars->print[g_vars->signal_id - 1] = g_vars->client_message_char;
		g_vars->client_message_char = 0;
		g_vars->counter = 0;
		g_vars->signal_id++;
		g_vars->grade = 131072;
	}
	else if (g_vars->counter == 32)
	{
		g_vars->counter = 0;
		g_vars->grade = 131072;
		g_vars->print = malloc(sizeof(char) * (g_vars->signal_count + 1));
		g_vars->signal_id++;
	}
}

void	add_one(int a, siginfo_t *info, void *some)
{
	(void)a;
	(void)some;
	if (g_vars->counter == 1)
		g_vars->minus = 1;
	else if (g_vars->signal_id == 0)
		g_vars->signal_count += g_vars->grade;
	else
		g_vars->client_message_char += g_vars->grade;
	ft_lines();
	if (g_vars->signal_id == g_vars->signal_count + 1)
	{
		ft_putstr_fd(g_vars->print, 1);
		g_vars->client_message_char = 0;
		free(g_vars->print);
		g_vars->signal_id = 0;
		g_vars->counter = 0;
		g_vars->signal_count = 0;
		g_vars->minus = 1;
		g_vars->grade = 4294967296;
		write(1, "\n", 1);
	}
	g_vars->counter++;
	g_vars->grade /= 2;
	usleep(30);
	kill(info->si_pid, SIGUSR1);
}

void	add_zero(int a, siginfo_t *info, void	*some)
{
	(void)a;
	(void)some;
	if (g_vars->counter == 1)
		g_vars->minus = -1;
	ft_lines();
	if (g_vars->signal_id == g_vars->signal_count + 1)
	{
		ft_putstr_fd(g_vars->print, 1);
		g_vars->client_message_char = 0;
		free(g_vars->print);
		g_vars->signal_id = 0;
		g_vars->counter = 0;
		g_vars->signal_count = 0;
		g_vars->minus = 1;
		g_vars->grade = 4294967296;
		write(1, "\n", 1);
	}
	g_vars->counter++;
	g_vars->grade /= 2;
	usleep(30);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	main_sig_one;
	struct sigaction	main_sig_zero;

	main_sig_one.sa_sigaction = add_one;
	main_sig_one.sa_flags = SA_SIGINFO;
	main_sig_zero.sa_sigaction = add_zero;
	main_sig_zero.sa_flags = SA_SIGINFO;
	ft_putstr_fd(ft_itoa(getpid()), 1);
	write(1, "\n", 1);
	g_vars = malloc(sizeof(t_vars));
	g_vars->client_message_char = 0;
	g_vars->signal_id = 0;
	g_vars->counter = 1;
	g_vars->signal_count = 0;
	g_vars->minus = 1;
	g_vars->grade = 2147483648;
	sigaction(SIGUSR1, &main_sig_one, NULL);
	sigaction(SIGUSR2, &main_sig_zero, NULL);
	while (1)
		pause();
	return (0);
}
