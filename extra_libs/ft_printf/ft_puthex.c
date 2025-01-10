/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:38:54 by dbailuk           #+#    #+#             */
/*   Updated: 2024/08/20 17:45:40 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long i, int uppercase)
{
	char	*hex;
	int		len;

	len = 0;
	if (uppercase == 2)
		hex = "0123456789ABCDEF";
	if (uppercase == 1)
		hex = "0123456789abcdef";
	if (i >= 16)
		len += ft_puthex(i / 16, uppercase);
	len += ft_putchr(hex[i % 16]);
	return (len);
}
// int main()
// {
// 	unsigned int i = 16;
// 	ft_puthex(i, 1);
// 	ft_putstr("\n");
// 	ft_puthex(i, 2);
// 	printf("\n%x\n", i);
// }