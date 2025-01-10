/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:42:11 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:39:10 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putnbr_uns(unsigned int nbr);
int	ft_puthex(unsigned long long i, int uppercase);
int	ft_putchr(char c);

#endif