/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:13:45 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/24 07:13:51 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choose_rule(char c, va_list ap)
{
	int	read;

	read = 0;
	if (c == 'c')
		read = ft_putchar_pf(va_arg(ap, int));
	else if (c == '%')
		read = write(1, "%%", 1);
	else if (c == 's')
		read = ft_putstr_pf(va_arg(ap, char *));
	else if (c == 'd')
		read = ft_putnbr_pf(va_arg(ap, int));
	else if (c == 'i')
		read = ft_putnbr_pf(va_arg(ap, int));
	else if (c == 'u')
		read = nbr_print(va_arg(ap, unsigned int));
	else if (c == 'p')
		read = ft_hex((unsigned long) va_arg(ap, void *), c);
	else if (c == 'x')
		read = ft_hex((unsigned int) va_arg(ap, int), c);
	else if (c == 'X')
		read = ft_hex((unsigned int) va_arg(ap, int), c);
	return (read);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		read;
	int		pos;

	va_start(ap, str);
	read = 0;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			read += choose_rule(str[pos + 1], ap);
			pos++;
		}
		else
			read += write(1, &str[pos], 1);
		pos++;
	}
	va_end(ap);
	return (read);
}
