/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/22 15:06:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <time.h>

char	*check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return ("0");
		i++;
	}
	return (str);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%sreceived%s\n", KGREEN, KNORMAL);
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
		return (ft_printf("%sInvalid Arg\n%s", KRED, KNORMAL));
	pid = ft_atoi(check_arg(argv[1]));
	if (pid == 0)
		return (ft_printf("%sInvalid PID\n%s", KRED, KNORMAL));
	signal(SIGUSR1, sig_handler);
	while (argv[2][i])
	{
		ft_printbinary((int)argv[2][i], pid);
		i++;
	}
	ft_printbinary('\0', pid);
	pause();
}
