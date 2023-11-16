/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:18:23 by alprival          #+#    #+#             */
/*   Updated: 2022/09/01 18:18:24 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	get_len(t_data *data, int sig)
{
	if (sig == SIGUSR2)
		data->lenght |= 1;
	if (++data->i != 32)
		data->lenght <<= 1;
	else
	{
		data->str = (char *)malloc(sizeof(char) * (data->lenght + 1));
		data->i = 0;
	}
}

static void	show_msg(t_data *data, pid_t pid)
{
	data->str[data->index] = data->c;
	data->c = 0;
	data->index++;
	data->i = 0;
	if (data->index == data->lenght)
	{
		data->str[data->index] = 0;
		ft_putstr_fd(data->str, 1);
		data->index = 0;
		ft_putchar_fd('\n', 1);
		free(data->str);
		data->lenght = 0;
		data->str = NULL;
		kill(pid, SIGUSR1);
	}
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static t_data	data;

	(void)context;
	if (!data.str)
		get_len(&data, sig);
	else
	{
		if (sig == SIGUSR2)
			data.c |= 1;
		if (++data.i != 8)
			data.c <<= 1;
		else
			show_msg(&data, info->si_pid);
	}
}

int	main(void)
{
	struct sigaction	s_sig;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sig.sa_sigaction = action;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, 0);
	sigaction(SIGUSR2, &s_sig, 0);
	while (1)
	{
	}
	return (0);
}
