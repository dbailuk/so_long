/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:27:20 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:35:40 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	num_length(int nmb)
{
	size_t	lenght;

	lenght = 0;
	if (nmb <= 0)
		lenght = 1;
	while (nmb)
	{
		lenght++;
		nmb /= 10;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			length;
	unsigned int	num;

	length = num_length(n);
	res = (char *)malloc((sizeof(char)) * (length + 1));
	if (!res)
		return (NULL);
	res[length] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num)
	{
		res[--length] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

// int main()
// {
// 	int nmb = -42;
// 	char *result = ft_itoa(nmb);
// 		printf("%s", result);
// 	free(result);
// }