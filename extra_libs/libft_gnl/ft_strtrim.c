/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:07:18 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:34:26 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && isset(s1[start], set))
		start++;
	end = (ft_strlen(s1));
	while ((end > start) && isset(s1[end - 1], set))
		end--;
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ptr[i++] = s1[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main()
{
	char const *s1 = "--+---hello---world---+-";
	char const *set = "-+";
	char *r = ft_strtrim(s1,set);
	printf("%s", r);
}*/