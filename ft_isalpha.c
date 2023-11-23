/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:43:56 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:24 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	lower;
	int	upper;
	int	alpha;

	lower = ('a' <= c && c <= 'z');
	upper = ('A' <= c && c <= 'Z');
	alpha = (lower || upper);
	return (alpha);
}
