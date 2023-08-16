/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:54:48 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 18:27:11 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	content = 0;
	free(content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = 0;
}
/*
int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	
	char	content0[] = "node0";
	char	content1[] = "node1";
	char	content2[] = "node2";

	node0 = ft_lstnew((void *)content0);
	node1 = ft_lstnew((void *)content1);
	node2 = ft_lstnew((void *)content2);
	
	ft_lstadd_front(&node0, node1);
	ft_lstadd_front(&node1, node2);
	
	ft_lstclear(&node0, del);

	printf("%s\n", (char *)node2->content);
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node0->content);

	free(node0);
	free(node1);
	free(node2);
	return (0);
}
*/
