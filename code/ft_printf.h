/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:13:58 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/24 07:14:00 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
//str
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *str);
//nbr
int		nbr_print(unsigned int n);
int		ft_putnbr_pf(int n);
//hex
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		hex_print(unsigned long n, char *str);
int		ft_hex(unsigned long n, char c);

#endif
