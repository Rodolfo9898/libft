/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:06:00 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 14:33:09 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	pos;

	if (*to_find == '\0')
		return ((char *)str);
	pos = ft_strlen((char *)to_find);
	while (*str != '\0' && len-- >= pos)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, pos) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
