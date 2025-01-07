/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:55:21 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:35:57 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > ((size_t)-1 / size))
	{
		return (NULL);
	}
	total_size = nmemb * size;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*int	main()
{
	int	*arr;
	size_t	num_elements = 5;

	arr = (int *)ft_calloc(num_elements, sizeof(int));
	size_t i = 0;
	while (i < num_elements)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
}*/