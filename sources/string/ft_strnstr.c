/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:06:00 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 23:47:53 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	find_len;
	size_t	i;

	if (*to_find == '\0')
		return ((char *)str);
	find_len = ft_strlen(to_find);
	i = 0;
	while (i + find_len <= len && str[i])
	{
		if (str[i] == *to_find && ft_strncmp(str + i, to_find, find_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
