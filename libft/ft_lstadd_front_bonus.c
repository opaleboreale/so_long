/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:25:13 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/14 02:23:48 by mferracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*new;
	t_list	*lst;
	t_list	**ptr;
	char	n0[] = "old";
	char	n1[] = "new";

	lst = ft_lstnew((void *)n0);
	new = ft_lstnew((void *)n1);
	ptr = &lst;
	ft_lstadd_front(ptr, new);
	printf("%s\n", (char *)(new->content));
	printf("%p\n", (int *)(new->next));
	printf("===============================\n");
	printf("%s\n", (char *)(lst->content));
	printf("%p\n", (int *)(lst->next));
	free(lst);
	free(new);
}
*/
