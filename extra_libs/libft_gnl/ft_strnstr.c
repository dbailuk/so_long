/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:38:37 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:34:32 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i1;
	size_t	llen;

	llen = 0;
	while (little[llen])
		llen++;
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while ((i <= len - llen) && big[i] != '\0')
	{
		i1 = 0;
		while (big[i + i1] == little[i1] && (i + i1) < len)
		{
			if (little[i1 + 1] == '\0')
			{
				return ((char *)(big + i));
			}
			i1++;
		}
		i++;
	}
	return (NULL);
}

/*int	main()
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	char	*ptr = ft_strnstr(largestring, smallstring, 10);
	printf("%s\n", ptr);
}*/