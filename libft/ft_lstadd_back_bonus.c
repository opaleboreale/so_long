/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:07:09 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 02:54:08 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
	{
		*lst = new;
		(*lst)->next = 0;
	}
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
/*
int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*last;
	char	content0[] = "node0";
	char	content1[] = "node1";
	char	content2[] = "node2";
	char	contlast[] = "last";

	node0 = ft_lstnew((void *)content0);
	node1 = ft_lstnew((void *)content1);
	node2 = ft_lstnew((void *)content2);
	//node2 = ft_lstnew(0);
	last = ft_lstnew((void *)contlast);
	ft_lstadd_front(&node0, node1);
	ft_lstadd_front(&node1, node2);
	ft_lstadd_back(&node2, last);
	printf("%s\n", (char *)ft_lstlast(node2)->content);
	free(last);
	free(node0);
	free(node1);
	free(node2);
	return (0);
}
*/
