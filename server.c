/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguerra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:21:37 by fguerra           #+#    #+#             */
/*   Updated: 2024/07/30 13:37:24 by fguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle(int signal, siginfo_t *info, void *content)
{
	static int	g_char;
	static int	g_bit;

	(void)info;
	(void)content;
	if (signal == SIGUSR1)
		g_char |= (0x01 << g_bit);
	g_bit++;
	if (g_bit == 8)
	{
		write(1, &g_char, 1);
		g_char = 0;
		g_bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sign;

	pid = getpid();
	printf("O meu pid é %d\n", pid);
	while (1)
	{
		sign.sa_sigaction = &handle;
		sign.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
