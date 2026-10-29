/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:20:37 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 23:30:00 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy copies front to back, which is safe for overlap when dest < src.
** Otherwise copy back to front so no source byte is overwritten before use.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (dest);
}
