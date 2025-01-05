/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:33:01 by dbailuk           #+#    #+#             */
/*   Updated: 2024/07/02 17:37:20 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main() {
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd('\n', 1);

	ft_putchar_fd('E', 2);
    ft_putchar_fd('r', 2);
    ft_putchar_fd('r', 2);
    ft_putchar_fd('o', 2);
    ft_putchar_fd('r', 2);
    ft_putchar_fd('\n', 2);

    return 0;
}*/
