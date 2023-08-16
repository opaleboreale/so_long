/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:04:21 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 02:35:26 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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
	int	size;

	node0 = ft_lstnew((void *)content0);
	node1 = ft_lstnew((void *)content1);
	node2 = ft_lstnew((void *)content2);
	ft_lstadd_front(&node0, node1);
	ft_lstadd_front(&node1, node2);
	size = ft_lstsize(node2);
	printf("%d\n", size);
	free(node0);
	free(node1);
	free(node2);
	return (0);
}*/
