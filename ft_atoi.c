/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:30:29 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 12:38:50 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	to_long(const char *str, int sign)
{
	long	res;
	long	lim;

	res = 0;
	lim = 9223372036854775807L;
	while (ft_isdigit(*str))
	{
		if (res > lim / 10 || (res == lim / 10 && *str - '0' > lim % 10))
		{
			if (sign == 1)
				return (lim);
			return (-lim - 1);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return ((int)to_long(str + i, sign));
}
