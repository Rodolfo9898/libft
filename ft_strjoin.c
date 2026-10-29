/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:21:49 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 21:10:54 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
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
	ft_memcpy(join, s1, size_s1);
	ft_memcpy(join + size_s1, s2, size_s2 + 1);
	return (join);
}
