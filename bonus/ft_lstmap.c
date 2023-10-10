/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fltorren <fltorren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:45:25 by fltorren          #+#    #+#             */
/*   Updated: 2023/10/10 16:48:52 by fltorren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
		return (NULL);
	ft_lstadd_back(&head, tmp);
	tail = head;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&head, tmp);
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
