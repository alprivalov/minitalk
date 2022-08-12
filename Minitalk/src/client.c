#include "minitalk.h"

// static void	action(int sig)
// {
// 	static int	received = 0;

// 	if (sig == SIGUSR1)
// 		++received;
// 	else
// 	{
// 		ft_putnbr_fd(received, 1);
// 		ft_putchar_fd('\n', 1);
// 		exit(0);
// 	}
// }

static void	ft_kill(int pid, char *str)
{
	int i;
	int i_bitshift;
	char c;

	i = 0;
	while(str[i])
	{
		i_bitshift = 8;
		c = str[i];
		while(i_bitshift--)
		{
			if(c >> i_bitshift & 1)
				kill(pid,SIGUSR2);
			else
				kill(pid,SIGUSR1);
			usleep(75);
		}
		i++;
	}
}

static void	ft_kill_len(int pid, int len)
{
	int i_bitshift;
	int	c;

	i_bitshift = 32;
	c = len;
	while(i_bitshift--)
	{
		if(c >> i_bitshift & 1)
			kill(pid,SIGUSR2);
		else
			kill(pid,SIGUSR1);
		usleep(75);
	}
}


int	main(int argc, char **argv)
{
	int pid;
	int len;

	if(ft_strlen(argv[2]) == 0)	
		exit(0);
	len = ft_strlen(argv[2]);
	if(argc != 3)
		return(0);
	pid = ft_atoi(argv[1]);
	ft_kill_len(pid,len);
	ft_kill(pid, argv[2]);
	sleep(1);
}
