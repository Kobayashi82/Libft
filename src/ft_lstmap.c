/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:24:40 by vzurera-          #+#    #+#             */
/*   Updated: 2023/11/30 16:53:18 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*tn_lst;

	if (!lst)
		return (NULL);
	n_lst = ft_lstnew(NULL);
	if (!n_lst)
		return (NULL);
	tn_lst = n_lst;
	while (lst)
	{
		n_lst->content = f(lst->content);
		if (!n_lst->content)
			return (ft_lstclear(&tn_lst, del), NULL);
		if (!lst->next)
			break ;
		lst = lst->next;
		n_lst->next = ft_lstnew(NULL);
		if (!n_lst->next)
			return (ft_lstclear(&tn_lst, del), NULL);
		n_lst = n_lst->next;
	}
	return (tn_lst);
}
