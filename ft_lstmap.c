/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:47:22 by rperez-t          #+#    #+#             */
/*   Updated: 2026/10/29 15:51:09 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	**tail;
	t_list	*node;
	void	*content;

	if (!f)
		return (NULL);
	result = NULL;
	tail = &result;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (del)
				del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		*tail = node;
		tail = &node->next;
		lst = lst->next;
	}
	return (result);
}
