/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:34:09 by alprival          #+#    #+#             */
/*   Updated: 2022/04/21 21:36:15 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg(va_list arg, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(arg, int));
	if (format == 's')
		i += ft_putstr(va_arg(arg, char *));
	if (format == 'd')
		i += ft_putnbr(va_arg(arg, int));
	if (format == 'i')
		i += ft_putnbr(va_arg(arg, int));
	if (format == 'x')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (format == 'p')
		i += ft_putnbr_base_adress(va_arg(arg, unsigned long long int),
				"0123456789abcdef");
	if (format == 'X')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (format == 'u')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		number;
	va_list	arg;

	i = 0;
	number = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			number += ft_arg(arg, format[i + 1]);
			i++;
		}
		else
			number += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (number);
}
