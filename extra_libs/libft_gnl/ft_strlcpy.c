/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:10:35 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:34:44 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size != 0)
	{
		i = 0;
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

/*int main()
{
	char s1[10] = "Hello";
	char *s2 = "Wow";
	size_t r = ft_strlcpy(s1,s2, 10);
	printf("%s\n", s1);
	printf("%zu", r);
}*/