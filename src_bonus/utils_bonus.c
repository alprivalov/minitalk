/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:18:37 by alprival          #+#    #+#             */
/*   Updated: 2022/09/01 18:18:38 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
