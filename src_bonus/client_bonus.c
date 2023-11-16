/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:18:07 by alprival          #+#    #+#             */
/*   Updated: 2022/09/01 18:18:08 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_kill(int pid, char *str)
{
	int		i;
	int		i_bitshift;
	char	c;

	i = -1;
	while (str[++i])
	{
		i_bitshift = 8;
		c = str[i];
		while (i_bitshift--)
		{
			if (c >> i_bitshift & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

void	ft_kill_len(int pid, int len)
{
	int	i_bitshift;
	int	c;

	i_bitshift = 32;
	c = len;
	while (i_bitshift--)
	{
		if (c >> i_bitshift & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	write(1, "MESSAGE RECEIVED\n", 18);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					len;
	struct sigaction	s_sig;

	sigemptyset(&s_sig.sa_mask);
	s_sig.sa_sigaction = action;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	len = ft_strlen(argv[2]);
	if (len == 0)
	{
		write(1, "MISSING MESSAGE\n", 16);
		sleep(1);
		exit(0);
	}
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_kill_len(pid, len);
	ft_kill(pid, argv[2]);
	sleep(1);
	return (0);
}
