/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:18:36 by asemykin          #+#    #+#             */
/*   Updated: 2025/03/18 12:27:32 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

//-----------------------------------------------------------------------

// sa.sa_sigaction = signal_action;
// 	-	sa.sa_sigaction is the field used for setting the signal handler
// 		function when you want to use extended signal handling
// 		(i.e., receiving additional information about the signal,
// 		such as the sending process ID).
// 	-	The handler function is signal_action,
//			meaning whenever SIGUSR1 is received,
// 		the signal_action function will be executed.
// By using sa.sa_sigaction instead of sa.sa_handler,
//	you're opting for the extended
// version of signal handling,
//	which allows the handler to receive more information
// about the signal (such as the signal's sending process ID).

// sa.sa_flags = SA_SIGINFO;
// 	-	sa.sa_flags defines additional options for how the signal should
//			be handled.
// 	-	SA_SIGINFO is a flag that tells the system to call the signal
//		handler with extended information
// 		(such as siginfo_t and ucontext_t structures).
// 		This allows your signal handler to access additional details
//		about the signal, like the PID of the process that sent the signal,
//		the signal number, etc.
// Using SA_SIGINFO allows your signal handler to receive more detailed
// information about the signal

// sigemptyset(&sa.sa_mask);
// 	This line initializes sa_mask to an empty set,
// 	meaning no additional signals are blocked when the signal handler
//	is running.

// sigemptyset(&sa.sa_mask);        // Clear all signals
// sigaddset(&sa.sa_mask, SIGUSR1); // Block SIGUSR1 while handling SIGUSR2
// sigaddset(&sa.sa_mask, SIGUSR2); // Block SIGUSR2 while handling SIGUSR2
// sigemptyset(&sa.sa_mask);		// This would bassically clear those signals
// 									// so sigemptyset has to be on the beginning

// sigaction(SIGUSR1, &sa, NULL);
// 	-	This line registers the signal handler (signal_action)
//		for the signal SIGUSR1.
// 	-	sigaction() is the system call that sets the signal handling
//		behavior for a specific signal. In this case,
//		it is configuring the handler for SIGUSR1.
// 	-	The second argument (&sa) is a pointer to the sigaction structure,
// 		which contains the handler function (signal_action),
//			the flags (SA_SIGINFO),
// 		and the signal mask (sa_mask).
// 	-	The third argument is set to NULL because we don't need to store the
//		previous signal handler for SIGUSR1 (we're not interested in it here).

//-----------------------------------------------------------------------

// SIGUSR1 and SIGUSR2
// When the process receives SIGUSR1,
//	it sets the least significant bit(LSB) to 1.
// When the process receives SIGUSR2, it leaves the LSB as 0.
// ✔ SIGUSR1 → Bit 1
// ✔ SIGUSR2 → Bit 0

// 'A' (01000001 in binary)
// Step			Signal Sent			Binary So Far
// 1			SIGUSR2 (0)			00000000
// 2			SIGUSR1 (1)			00000001
// 3			SIGUSR2 (0)			00000010
// 4			SIGUSR2 (0)			00000100
// 5			SIGUSR2 (0)			00001000
// 6			SIGUSR2 (0)			00010000
// 7			SIGUSR2 (0)			00100000
// 8			SIGUSR1 (1)			01000001 (which is 'A')

// shifting one bit to the left is equal like multiply by 2
// current_char <<= 1;
// current_char = current_char << 1;
// current_char = current_char * 2;

// shifting one bit to the right is like dividing by 2
// current_char = current_char >> 1;
// current_char = current_char / 2;

// current_char |= (signal == SIGUSR1);

// if (signal == SIGUSR1)
// {
//     current_char = current_char | 1;
// }

// current_char = current_char | (signal == SIGUSR1);

// Bitwise OR (|): 	This operator compares each bit of the operands.
//					If either bit is 1, the result is 1.
//					If both bits are 0, the result is 0.
// Assignment (=): 	This assigns the result of the operation to
//					current_char.

//-----------------------------------------------------------------------

// Unicode characters are represented in UTF-8 as 1 to 4 bytes.
// 		ASCII characters (A-Z, 0-9) use 1 byte (e.g., A = 01000001).
// 		Emojis & non-Latin characters (😊, 你好) use multiple bytes.
//     		😊 (U+1F60A) → F0 9F 98 8A (4 bytes).
//     		你 (U+4F60) → E4 BD A0 (3 bytes).

// The client sends 8 bits (1 byte) at a time.
// 		Since UTF-8 already breaks Unicode into bytes,
// 		the program doesn't need to "know" Unicode — it just transmits
//		the bytes.

// The server receives & prints the bytes
// 		It reconstructs each byte separately.
// 		When all bytes of a character are received,
//			they form a valid UTF-8 sequence.
// 		If the terminal supports UTF-8,
//			it correctly displays Unicode characters.

// Unicode works because UTF-8 naturally splits characters into multiple bytes,
// the program sends and reconstructs data byte-by-byte without modification.
