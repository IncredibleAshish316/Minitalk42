/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:57:55 by anepali           #+#    #+#             */
/*   Updated: 2022/12/31 15:16:51 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	from_server(int sig)
{
	static int	sent;

	if (sig == SIGUSR1)
	{
		ft_printf("%d signal sent\n", sent);
		exit(0);
	}
	if (sig == SIGUSR2)
		sent++;
}

static void	sig_error(void)
{
	ft_printf("possible signal error\n");
	exit(0);
}

static void	char_to_bin(unsigned char c, int server_pid)
{
	int	n_bits;

	n_bits = 0;
	while (n_bits < 8)
	{
		if (c & 128)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				sig_error();
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				sig_error();
		}
		c <<= 1;
		n_bits++;
		pause();
		usleep(100);
	}
}

static void	ft_send_text(int server_pid, char *bits)
{
	int	i;

	i = 0;
	while (bits[i] != '\0')
	{
		char_to_bin(bits[i], server_pid);
		i++;
	}
	char_to_bin('\0', server_pid);
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	client_pid;

	client_pid = 0;
	server_pid = 0;
	if (argc != 3 || argv[2] == NULL)
		return (1);
	signal(SIGUSR1, from_server);
	signal(SIGUSR2, from_server);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (1);
	ft_send_text(server_pid, argv[2]);
	return (0);
}
