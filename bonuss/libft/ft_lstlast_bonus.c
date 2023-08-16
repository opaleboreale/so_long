/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:05:13 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 02:28:29 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
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
	printf("%s\n", (char *)(ft_lstlast(node2))->content);
	free(node0);
	free(node1);
	free(node2);
}
*/
