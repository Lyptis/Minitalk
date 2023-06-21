/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/21 17:29:48 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <time.h>

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("received\n");
	exit(1);
}

void	ft_printbinary(int c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	while (argv[2][i])
	{
		ft_printbinary((int)argv[2][i], pid);
		i++;
	}
	ft_printbinary('\0', pid);
	pause();
}
