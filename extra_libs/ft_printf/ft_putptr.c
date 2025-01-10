/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:29:58 by dbailuk           #+#    #+#             */
/*   Updated: 2024/08/20 17:47:15 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int					len;
	unsigned long long	nbr;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	nbr = (unsigned long long)ptr;
	len += ft_putstr("0x");
	len += ft_puthex(nbr, 1);
	return (len);
}
// int main()
// {
// 	void *ptr = 0;
// 	printf("%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	ft_printf("%p, %p", (void *)LONG_MIN, (void *)LONG_MAX);
// }