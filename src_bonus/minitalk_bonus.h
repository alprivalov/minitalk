/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:19:18 by alprival          #+#    #+#             */
/*   Updated: 2022/09/01 18:19:37 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_data {
	char	c;
	int		i;
	char	*str;
	int		lenght;
	int		index;
	int		client_pid;
}				t_data;

//			  utils				//

int			ft_atoi(const char *nptr);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_itoa(int n);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);

//		minitalk functions		//

static int	ft_len(int n);
static char	*ft_echange(char *tab, int n);
static char	*ft_populate(char *tab, int n);

#endif
