#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
typedef struct s_data {
char	*str;
int		lenmax;
int		flag;
}				t_data;


int			ft_atoi(const char *nptr);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
static char	*ft_echange(char *tab, int n);
static int	ft_len(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
static char	*ft_populate(char *tab, int n);
#endif