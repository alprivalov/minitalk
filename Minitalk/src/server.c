#include "minitalk.h"


static void	action(int sig, siginfo_t *info, void *context)
{
	static char		c;
	static int 		i;
	static char		*str;
	static int		lenght;
	static int		flag;
	static int 		index;
	static long long int		lenmax;

	if(flag == 0)
	{
		if (sig == SIGUSR2)
			lenght |= 1;
		if (++i != 32)
			lenght <<= 1;
		else 
		{
			lenmax = lenght;
			str = malloc(sizeof(char) * lenmax + 1);
			str[lenmax + 1] = '\0';
			lenght = 0;
			i = 0;
			flag = 1;
		}
	}
	else
	{
		if (sig == SIGUSR2)
			c |= 1;
		if (++i != 8)
			c <<= 1;
		else
		{
			str[index] = c;
			c = 0;
			index++;
			i = 0;
			if (index == lenmax)
			{
				ft_putstr_fd(str,1);
				index = 0;
				flag = 0;
				ft_putchar_fd('\n', 1);
				free(str);
			}
		}
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
		pause();
	return (0);
}
