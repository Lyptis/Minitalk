/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/22 14:51:59 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	received(char *str, pid_t client)
{
	if (!str)
	{
		kill(client, SIGUSR1);
		return ;
	}
	ft_printf("%s", str);
	free(str);
	
}

char	*add_to_string(char *str, char c)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	while (str && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[++i] = '\0';
	if (str != NULL)
		free(str);
	return (res);
}

void	signal_handler(int sig, siginfo_t *sa, void *ptr)
{
	static int		i;
	static int		c;
	static char		*str;
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
		if (c == 0)
		{
			received(str, client);
			str = NULL;
			client = 0;
		}
		else
			str = add_to_string(str, c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("PID :%d\n", getpid());
	sig.sa_sigaction = &signal_handler;
	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		continue ;
}
