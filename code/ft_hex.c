/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:13:01 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/24 07:13:06 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	int				i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (n)
	{
		dest[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}

int	hex_print(unsigned long n, char *str)
{
	int				print;

	print = 0;
	if (n > 15)
		print += hex_print(n / 16, str);
	print += write(1, &str[n % 16], 1);
	return (print);
}

int	ft_hex(unsigned long n, char c)
{
	int				print;
	char			sys[16];

	print = 0;
	if (c == 'x')
		ft_memcpy(sys, "0123456789abcdef", 16);
	else if (c == 'p')
	{
		print = write(1, "0x", 2);
		ft_memcpy(sys, "0123456789abcdef", 16);
	}
	else
		ft_memcpy(sys, "0123456789ABCDEF", 16);
	if (n < 0)
		n *= -1;
	print += hex_print(n, sys);
	return (print);
}
