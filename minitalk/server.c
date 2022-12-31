/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anepali <anepali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:23:42 by anepali           #+#    #+#             */
/*   Updated: 2022/12/31 14:57:45 by anepali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(char *c, int *bit, int *client_pid)
{
	ft_printf("%c", *c);
	if (*c == '\0')
	{
		ft_printf("\nSignal recieved from client PID:%d\n", client_pid);
		*c = 0;
		kill(*client_pid, SIGUSR1);
		return ;
	}
	*bit = 0;
}

void	from_client(int sig, siginfo_t *info, void *context)
{
	static int	n_bits;
	static char	c;
	static int	client_pid;
	static int	pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	pid = info->si_pid;
	if (client_pid != pid)
	{
		client_pid = pid;
		n_bits = 0;
		c = 0;
	}
	c |= (sig == SIGUSR1);
	n_bits++;
	if (n_bits == 8)
		bin_to_char(&c, &n_bits, &client_pid);
	c <<= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %u\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = from_client;
	act.sa_flags = SA_SIGINFO;
	while (1 == 1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (0);
}
