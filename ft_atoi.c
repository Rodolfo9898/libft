/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:30:29 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 23:30:00 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** Clamps to LONG_MAX / LONG_MIN on overflow, like strtol, so that the cast
** to int in ft_atoi gives the same result as glibc's atoi.
*/
static long	to_long(const char *str, int sign)
{
	long	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		if (res > LONG_MAX / 10
			|| (res == LONG_MAX / 10 && *str - '0' > LONG_MAX % 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

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
