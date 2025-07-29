/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:19:29 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/18 12:19:34 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	signal_action(int signal, siginfo_t *info, void *context)
{
	static int	character;
	static int	bit;
	static int	current_client;

	current_client = info->si_pid;
	(void)context;
	character |= (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			kill(current_client, SIGUSR2);
		character = 0;
		bit = 0;
	}
	else if (bit < 8)
		character <<= 1;
	kill(current_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID is: %i\n", getpid());
	sa.sa_sigaction = signal_action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
