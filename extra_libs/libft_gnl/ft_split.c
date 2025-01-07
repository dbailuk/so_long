/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:32:08 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/07 16:35:03 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_freeup(char **strs, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

void	ft_strcpy(char *word, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j] != c && str[j] != '\0')
	{
		word[i] = str[j];
		i++;
		j++;
	}
	word[i] = '\0';
}

char	*ft_stralloc(char *str, char c, int *k)
{
	char	*word;
	int		len;
	int		j;

	j = *k;
	word = NULL;
	while (str[*k] != '\0' && str[*k] == c)
		(*k)++;
	j = *k;
	len = 0;
	while (str[*k] != '\0' && str[*k] != c)
	{
		len++;
		(*k)++;
	}
	if (len > 0)
	{
		word = (char *)malloc(sizeof(char) * (len + 1));
		if (word == NULL)
			return (NULL);
		ft_strcpy(word, str, c, j);
	}
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount((char *)str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(((char *)str), c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs, i);
			return (NULL);
		}
		i++;
	}
	return (strs);
}

/*int main()
{
	char const *s = " HEll Nahh Hehehell naaahh   ";
	char **res = ft_split(s, ' ');
	size_t	i = 0;
	while (res[i])
	{
		printf("Substring %zu: %s\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(res);
}*/