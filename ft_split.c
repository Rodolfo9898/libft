/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:48:25 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 11:32:57 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **result, int word)
{
	while (word--)
		free(result[word]);
	free(result);
}

static int	split_words(char **result, char const *s, char c, int word)
{
	int		begin;
	int		last;

	last = 0;
	begin = 0;
	while (s[last])
	{
		if (s[last] == c || s[last] == 0)
			begin = last + 1;
		if (s[last] != c && (s[last + 1] == c || s[last + 1] == 0))
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
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}
