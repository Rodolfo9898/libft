/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:26:12 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 14:34:20 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	lower;
	int	diff;

	lower = ('a' <= c && c <= 'z');
	diff = 'a' - 'A';
	if (lower)
		return (c - diff);
	return (c);
}
