/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:48:25 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/30 11:49:28 by rperez-t         ###   ########.fr       */
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

static void	free_words(char **result, size_t word)
{
	while (word--)
		free(result[word]);
}

static int	split_words(char **result, char const *s, char c, size_t word)
{
	size_t	word_start;
	size_t	i;

	i = 0;
	word_start = 0;
	while (s[i])
	{
		if (s[i] == c)
			word_start = i + 1;
		if (is_word_end(s, i, c))
		{
			result[word] = malloc(sizeof(char) * (i - word_start + 2));
			if (!result[word])
			{
				free_words(result, word);
				return (0);
			}
			ft_memcpy(result[word], s + word_start, i - word_start + 1);
			result[word][i - word_start + 1] = '\0';
			word++;
		}
		i++;
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
	{
		free(result);
		return (NULL);
	}
	return (result);
}
