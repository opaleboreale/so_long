/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:47:33 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 18:36:54 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	f(void *content)
{
	(void)content;
	printf("%s\n", "iter");
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
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

	printf("%s\n", (char *)(node2->content));
	printf("%s\n", (char *)(node1->content));
	printf("%s\n", (char *)(node0->content));
	printf("=============================\n");
	
	ft_lstiter(node1, *f);

	free(node0);
	free(node1);
	free(node2);
	return (0);
}
*/
