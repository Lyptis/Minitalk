/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/21 17:32:45 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	signal_handler(int sig, siginfo_t *sa, void *ptr)
{
	static int	i;
	static int	c;
	static pid_t	client;

	(void)ptr;
	if (!client)
		client = sa->si_pid;
	if (sig == SIGUSR1)
		c = c + (1 << i++);
	else
		i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		if (c == 0)
		{
			kill(client, SIGUSR1);
			client = 0;
		}
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sig;

	
	ft_printf("PID :%d\n", getpid());
	sig.sa_sigaction = &signal_handler;
	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		continue ;
}
