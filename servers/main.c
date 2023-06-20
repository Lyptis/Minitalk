/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/20 12:10:34 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	signal_handler(int sig)
{
	static int	i;
	static int	c;

	if (sig == SIGUSR1)
		c = c + (1 << i++);
	else
		i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%d ", c);
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID :%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		continue ;
}
