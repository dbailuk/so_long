/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:36:24 by dbailuk           #+#    #+#             */
/*   Updated: 2024/06/20 16:13:46 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s1;
	char		c1;

	s1 = (const char *)s;
	c1 = (char)c;
	while (n--)
	{
		if (*s1 == c1)
			return ((void *)s1);
		s1++;
	}
	return (NULL);
}

/*int main()
{
	const char	*s = "roeiovjw      ";
	char	c = 'j';
	char	*r = ft_memchr(s, c, 11);
	char	*t = memchr(s, c, 11);
	printf("%s\n", r);
	printf("%s", t);
}*/