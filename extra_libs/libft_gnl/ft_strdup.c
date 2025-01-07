/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:58:23 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/23 16:03:33 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (i < ft_strlen(str))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*int	main()
{
	const char	*s1 = "What a freak";
	char *r = ft_strdup(s1);
	printf("%s\n", r);
	free(r);
}*/