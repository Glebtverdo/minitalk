/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vearleen <vearleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:56:52 by vearleen          #+#    #+#             */
/*   Updated: 2021/12/22 17:27:46 by vearleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"all.h"

void	receved(int number, struct __siginfo *info, void *some)
{
	(void)number;
	(void)info;
	(void)some;
	write(1, "receved   ", 10);
}

int	*ft_dec_to_bin(int number, int bit_count)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * (bit_count + 1));
	result[0] = 1;
	if (number < 0)
	{
		result[0] = 0;
		number *= -1;
	}
	while (number)
	{
		result[bit_count] = number % 2;
		number /= 2;
		bit_count--;
	}
	while (bit_count)
	{
		result[bit_count] = 0;
		bit_count--;
	}
	return (result);
}

void	ft_send_number(char **argv)
{
	int	*send_messadge;
	int	i;

	send_messadge = ft_dec_to_bin(ft_strlen(argv[2]), 31);
	if (!send_messadge)
	{
		write(1, "MALLOC ERROR\n", 13);
		exit(0);
	}
	i = 0;
	while (i < 32)
	{
		write(1, "send ", 5);
		if (send_messadge[i] == 1)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		pause();
		usleep(30);
		i++;
	}
	free(send_messadge);
}

void	ft_send_char(char **argv, int *i)
{
	int	counter;
	int	*send_messadge;

	counter = 0;
	send_messadge = ft_dec_to_bin(argv[2][*i], 16);
	if (!send_messadge)
	{
		write(1, "MALLOC ERROR\n", 13);
		exit(0);
	}
	counter = 0;
	while (counter < 17)
	{
		write(1, "send ", 5);
		if (send_messadge[counter] == 1)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		counter++;
		pause();
		usleep(30);
	}
	free(send_messadge);
	*i += 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	main_sig;
	int					i;

	if (argc != 3)
		ft_error("ERROR WRONG INPUT\n", 18);
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_error("ERROR WRONG PID\n", 16);
		i++;
	}
	main_sig.sa_sigaction = receved;
	main_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &main_sig, NULL);
	ft_send_number(argv);
	i = 0;
	while (argv[2][i])
		ft_send_char(argv, &i);
	return (0);
}
