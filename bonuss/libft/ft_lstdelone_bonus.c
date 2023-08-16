/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mferracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:42:33 by mferracc          #+#    #+#             */
/*   Updated: 2022/11/11 00:54:28 by mferracc         ###   ########.fr       */
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
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*node0;
	char	content0[] = "node0";

	node0 = ft_lstnew((void *)content0);
	ft_lstdelone(node0, *del);
	printf("%s\n", (char *)(node0->content));
	free(node0);
	return (0);
}
*/
