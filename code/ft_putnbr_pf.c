/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:14:15 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/24 07:14:18 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_print(unsigned int n)
{
	int		print;

	print = 0;
	if (n > 9)
		print += nbr_print(n / 10);
	print += ft_putchar_pf((char)(n % 10 + '0'));
	return (print);
}

int	ft_putnbr_pf(int n)
{
	unsigned int	nb;
	int				print;

	print = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int)(n * -1);
		print = 1;
	}
	else
		nb = (unsigned int)n;
	print += nbr_print(nb);
	return (print);
}
