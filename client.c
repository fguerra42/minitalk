/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguerra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:50:20 by fguerra           #+#    #+#             */
/*   Updated: 2024/07/30 13:21:25 by fguerra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	send_char(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		server_pid;
	char	*mensagem;

	if (argc != 3)
	{
		fprintf(stderr, "Uso: %s <PID_servidor> <mensagem>\n", argv[0]);
		return (1);
	}	
	mensagem = argv[2];
	server_pid = atoi(argv[1]);
	i = 0;
	while (mensagem[i] != '\0')
	{
		send_char(server_pid, mensagem[i]);
		i++;
	}
	send_char(server_pid, '\n');
	return (0);
}
