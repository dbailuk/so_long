/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:04:22 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:34:48 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	srclen;
	size_t	dstlen;

	srclen = 0;
	dstlen = 0;
	while (src[srclen] != '\0')
		srclen++;
	while ((dst[dstlen] != '\0') && (dstlen < size))
		dstlen++;
	if (dstlen == size)
		return (size + srclen);
	i = 0;
	while ((dstlen + i < size - 1) && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen + i < size)
	{
		dst[dstlen + i] = '\0';
	}
	return (srclen + dstlen);
}

/*int	main()
{
	char s1[10] = "Hello";
	char *s2 = "Wow";
	size_t r = ft_strlcat(s1, s2, sizeof(s1));
	printf("%s\n", s1);
	printf("%zu", r);
}*/