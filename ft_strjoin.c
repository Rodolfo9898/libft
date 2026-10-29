/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:49 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 14:44:25 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	idx_join;
	char	*join;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
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
