/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:59:29 by dbailuk           #+#    #+#             */
/*   Updated: 2024/06/18 16:04:31 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p++ = (unsigned char )c;
	}
	return (s);
}

/*int	main()
{
	char	buffer[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		buffer[i] = 'D';
		i++;
	}

	ft_memset(buffer, 'C', 5);
	i = 0;
	while (i < 5)
	{
		printf("%c ", buffer[i]);
		i++;
	}
	return (0);
}*/
