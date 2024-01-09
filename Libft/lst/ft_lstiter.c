/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:56:39 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:28 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
void	add_one(void *i)
{
	*(int *)i += 1;
}*/

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <assert.h>

int	main(void)
{
	t_list  *lst;
	int     a;
	int     b;

	a = 1;
	b = 2;
	lst = ft_lstnew(&a);
	ft_lstadd_back(&lst, ft_lstnew(&b));

	ft_lstiter(lst, add_one);
	assert(*(int *)lst->content == 2);
	assert(*(int *)lst->next->content == 3);
	return (0);
}*/