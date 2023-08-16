/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 02:22:13 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 21:07:26 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*f(void *content)
{
	(void)content;
	char *new = ft_strdup("new");

	return (new);
}

void	del(void *content)
{
	content = 0;
	free(content);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	newlist = 0;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == 0)
		{
			ft_lstclear(&lst, del);
		}
		else
		{
			ft_lstadd_back(&newlist, node);
		}
		lst = lst->next;
	}
	return (newlist);
}
/*
int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*newlist;

	char	content0[] = "node0";
	char	content1[] = "node1";
	char	content2[] = "node2";

	node0 = ft_lstnew((void *)content0);
	node1 = ft_lstnew((void *)content1);
	node2 = ft_lstnew((void *)content2);

	ft_lstadd_front(&node0, node1);
	ft_lstadd_front(&node1, node2);

	newlist = ft_lstmap(node2, f, del);

	free(node0);
	free(node1);
	free(node2);
	free(newlist);
	return (0);
}
*/
