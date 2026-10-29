/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:44:06 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 12:41:03 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_idx;
	size_t	value;

	i = 0;
	while (i < size && dest[i] != '\0')
		i++;
	value = ft_strlen(src) + i;
	if (i == size)
		return (value);
	src_idx = 0;
	while (src[src_idx] != '\0' && i + 1 < size)
	{
		dest[i] = src[src_idx];
		src_idx++;
		i++;
	}
	dest[i] = '\0';
	return (value);
}
