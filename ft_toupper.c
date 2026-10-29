/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:26:12 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 11:32:57 by rperez-t         ###   ########.fr       */
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
