/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:35:52 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/23 14:33:25 by rperez-t         ###   ########.fr       */
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
		if (s[i] == (unsigned char)c)
			found = (char *)(s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		found = (char *)(s + i);
	return (found);
}
