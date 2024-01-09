/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:45:47 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:33 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmpf;
	t_list	*temp;

	new = NULL;
	while (lst)
	{
		tmpf = f(lst->content);
		temp = ft_lstnew(tmpf);
		if (!temp)
		{
			ft_lstclear(&new, del);
			del(tmpf);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
/*
void	*add_one(void *i)
{
	int		*t;


	t = (int *)malloc(sizeof (int));
	*t = *(int *)i + 1;
	return (t);
}

int	main(void)
{
	t_list  *lstOrig;
	t_list *mappedList;
	int     a;
	int     b;

	a = 1;
	b = 2;
	lstOrig = ft_lstnew(&a);
	ft_lstadd_back(&lstOrig, ft_lstnew(&b));

	mappedList = ft_lstmap(lstOrig, add_one, free);
	assert(*(int *)mappedList->content == 2);
	assert(*(int *)mappedList->next->content == 3);
	return (0);
}*/