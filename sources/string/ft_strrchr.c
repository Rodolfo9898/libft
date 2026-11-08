/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:35:52 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 14:44:25 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*found;

	i = 0;
	found = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			found = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		found = (char *)(s + i);
	return (found);
}
