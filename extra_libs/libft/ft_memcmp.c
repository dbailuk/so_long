/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:15:31 by dbailuk           #+#    #+#             */
/*   Updated: 2024/07/02 19:02:49 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*m1;
	const unsigned char	*m2;

	m1 = (const unsigned char *)s1;
	m2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (m1[i] - m2[i]);
		i++;
	}
	return (0);
}

/*int	main()
{
	char	*s1 = "Hello r";
	char	*s2 = "Hello           fefffwFEI";
	int	r = ft_memcmp(s1, s2, 100);
	int r1 = memcmp(s1, s2, 100);
	printf("%i\n", r);
	printf("%i", r1);
}*/