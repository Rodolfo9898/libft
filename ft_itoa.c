/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:56 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 14:44:25 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digit(long num)
{
	int	digits;

	digits = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		digits++;
	while (num != 0)
	{
		num = num / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*result;

	len = num_digit(n);
	num = n;
	if (num < 0)
		num = -num;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num != 0)
	{
		result[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
