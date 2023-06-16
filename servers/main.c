/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/16 17:25:40 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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


void	signal_handler(int sig)
{
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
	pid_t	pid_s;
	i = 0;
	c = 0;

	pid_s = getpid();
	ft_printf("%d\n", pid_s);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		continue;
}
