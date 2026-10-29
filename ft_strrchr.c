/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:35:52 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 12:41:52 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;

	i = 0;
	found = 0;
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
