/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:20:08 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/18 12:20:19 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int	g_received;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	if (signal == SIGUSR2)
		ft_printf(">> SIGNAL FROM SERVER RECEIVED <<\n");
}

void	send_character(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			usleep(50);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("### Wrong Parameter Input ###\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_character(pid, argv[2][i]);
		i++;
		if (argv[2][i] == '\0')
			send_character(pid, argv[2][i]);
	}
}
