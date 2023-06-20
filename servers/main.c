/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/18 15:41:48 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

unsigned char c;
int			i;

char	setchar(char c)
{
	if (!c)
		return (0);
	else
		return (c);
}

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		res *= ft_recursive_power(nb, power - 1);
	}
	return (res);
}


void	signal_handler(int sig, siginfo_t *s_info, void *ptr)
{
	pid_t	client;

	(void)ptr;
	client = 0;
	if (!client)
		client = s_info->si_pid;
	if (sig == SIGUSR1)
	{
		c = c + ft_recursive_power(2, i);
		i++;
	}
	else
		i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	i = 0;
	c = 0;
	ft_printf("PID :%d\n", getpid());
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		continue ;
}
