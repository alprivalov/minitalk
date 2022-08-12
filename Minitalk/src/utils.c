#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	neg;

	neg = 1;
	i = 0;
	result = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10;
		result = result + nptr[i] - '0';
		i++;
	}
	return (result * neg);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
		return ;
	index = -1;
	while (s[++index])
		write (fd, &s[index], 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return(i);
	while (s[i])
	{
		i++;
	}
	return (i);
}
static char	*ft_populate(char *tab, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		tab[0] = '-';
		i++;
	}
	while (n > 0)
	{
		tab[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static int	ft_len(int n)
{
	int	neg;
	int	i;

	neg = 0;
	i = 1;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		neg++;
	}
	while ((unsigned int)n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + neg);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;
	int		len;

	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (0);
	len = (nmemb * size);
	i = 0;
	tab = malloc(len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i] = 'c';
		i++;
	}
	return (tab);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		srclen;
	char	*str;

	str = (char *)src;
	i = 0;
	srclen = ft_strlen(str);
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

static char	*ft_echange(char *tab, int n)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(tab) - 1;
	if (n < 0)
		i++;
	while (i < j)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		j--;
		i++;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;

	len = ft_len(n);
	tab = ft_calloc(sizeof(char), len);
	if (!tab)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(tab, "-2147483648", 12);
		return (tab);
	}
	if (!tab)
		return (NULL);
	ft_populate(tab, n);
	ft_echange(tab, n);
	if (tab[0] == 0)
		tab[0] = '0';
	return (tab);
}