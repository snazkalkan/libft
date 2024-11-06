/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:13:30 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/04 00:17:55 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
			return (ft_lstclear(&result, del), NULL);
		node = ft_lstnew(temp);
		if (!node)
			return (ft_lstclear(&result, del), del(temp), NULL);
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
