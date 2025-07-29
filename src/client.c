/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:19:51 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/18 12:27:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_received;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
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
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_character(pid, argv[2][i]);
		i++;
		if (argv[2][i] == '\0')
			send_character(pid, argv[2][i]);
	}
}

// character >> i: 			This shifts the bits of character
//								to the right by i positions. The bit at
// 								position i moves to the least significant bit.
// (character >> i) & 1: 	This performs a bitwise AND with 1 to isolate the
//								least significant bit. If the i-th bit was 1,
//								the result will be 1. Otherwise, it will be 0.

// sa.sa_handler = signal_handler;
// 	This sets the sa_handler field to signal_handler,
// 	whenever the specified signal (SIGUSR1) is received,
// 	the function signal_handler will be executed.

// sigemptyset(&sa.sa_mask);
// 	sigemptyset() initializes the sa_mask field to an empty set,
// 	meaning no signals will be blocked while signal_handler is running.

// sa.sa_flags = 0;
// 	This ensures default behavior for the signal handling
//	(no special options enabled).

// sigaction(SIGUSR1, &sa, NULL);
// 	This tells the operating system that whenever the process receives SIGUSR1,
// 	it should execute signal_handler.