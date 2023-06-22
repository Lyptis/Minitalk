/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:12:58 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/22 14:57:51 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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

void	signal_handler(int sig)
{
	static int	i;
	static int	c;
	static char	*str;

	if (sig == SIGUSR1)
		c = c + (1 << i++);
	else
		i++;
	if (i == 8)
	{
		if (c == 0)
		{
			if (str)
			{
				ft_printf("%s", str);
				free(str);
			}
			str = NULL;
		}
		else
			str = add_to_string(str, c);
		i = 0;
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
