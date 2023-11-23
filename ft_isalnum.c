/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:56:42 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:18 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	digit;
	int	alpha;
	int	numalpha;

	alpha = ft_isalpha(c);
	digit = ft_isdigit(c);
	numalpha = (alpha || digit);
	return (numalpha);
}
