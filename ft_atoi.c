/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:30:29 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:08 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	int	space;
	int	horizontal;
	int	carriage;

	space = (c == ' ');
	horizontal = ('\t' <= c);
	carriage = (c <= '\r');
	return ((horizontal && carriage) || space);
}

static int	ft_signcheck(char c)
{
	int	pose;
	int	nege;

	pose = (c == '+');
	nege = (c == '-');
	return (pose || nege);
}

static int	ft_numbers(char c)
{
	int	digits;

	digits = (('0' <= c) && (c <= '9'));
	return (digits);
}

int	ft_atoi(const char *str)
{
	long	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_signcheck(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_numbers(str[i]))
	{
		result = ((result * 10) + (str[i] - '0'));
		i++;
	}
	result = result * sign;
	return (result);
}
/*
#include<stdio.h>
int main()
{
	printf("%d\n",ft_atoi("92233720368547758080000"));
	printf("%d\n",atoi("922337203685477580800000"));
	return 0;
}*/