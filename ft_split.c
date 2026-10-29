/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:48:25 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 15:51:09 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word_end(char const *s, size_t i, char c)
{
	return (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'));
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (is_word_end(s, i, c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **result, size_t word)
{
	while (word--)
		free(result[word]);
	free(result);
}

static int	split_words(char **result, char const *s, char c, size_t word)
{
	size_t	begin;
	size_t	last;

	last = 0;
	begin = 0;
	while (s[last])
	{
		if (s[last] == c)
			begin = last + 1;
		if (is_word_end(s, last, c))
		{
			result[word] = malloc(sizeof(char) * (last - begin + 2));
			if (!result[word])
			{
				free_all(result, word);
				return (0);
			}
			ft_strlcpy(result[word], (s + begin), last - begin + 2);
			word++;
		}
		last++;
	}
	result[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}
