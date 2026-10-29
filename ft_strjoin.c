/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:49 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 11:32:57 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		idx_join;
	char	*join;
	int		size_s1;
	int		size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	join = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	idx_join = 0;
	while (s1[i])
		join[idx_join++] = s1[i++];
	i = 0;
	while (s2[i])
		join[idx_join++] = s2[i++];
	join[idx_join] = '\0';
	return (join);
}
