/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:26:12 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 14:34:10 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	upper;
	int	diff;

	upper = ('A' <= c && c <= 'Z');
	diff = 'a' - 'A';
	if (upper)
		return (c + diff);
	return (c);
}
