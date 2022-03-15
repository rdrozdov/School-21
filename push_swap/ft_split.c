/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:35:11 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 14:20:24 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	counter;
	int	separator;

	counter = 0;
	separator = 1;
	if (s)
	{
		while (*s)
		{
			if (separator == 1 && *s != c)
			{
				separator = 0;
				counter++;
			}
			else if (*s == c)
				separator = 1;
			s++;
		}
	}
	return (counter);
}

static char	*create_word(const char *s, int start, int finish, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	if (count_words(s, c) == 1)
	{
		ft_atoi(word);
		exit(0);
	}
	return (word);
}

static char	**free_memory(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**split_maker(char const *s, char c, char **split)
{
	int		index;
	int		i;
	size_t	n;

	i = 0;
	index = -1;
	n = 0;
	while (n <= ft_strlen((char *)s))
	{
		if (s[n] != c && index < 0)
			index = n;
		else if ((s[n] == c || n == ft_strlen((char *)s)) && index >= 0)
		{
			split[i] = create_word(s, index, n, c);
			if (split[i++] == NULL)
				return (free_memory(split));
			index = -1;
		}
		n++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	split = split_maker(s, c, split);
	return (split);
}
