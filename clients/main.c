/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/16 17:25:39 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <time.h>

void	ft_printbinary(unsigned char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ( c & 1)
		{
			kill(pid, SIGUSR1);
			ft_printf("1"); //debug
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("0"); //debug
		}
		i++;
		c = c >> 1;
		usleep(100);
	}
}

void	ft_getchar(unsigned char *str, pid_t pid)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		ft_printbinary((unsigned char)str[i], pid);
		ft_printf("\n"); //debug
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	ft_getchar((unsigned char *)argv[2], pid);
}
