/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:58:46 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:24 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	// Crée un élément de liste avec du contenu
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	new_node->content = (void *)ft_strdup("Hello, World");
		// Duplication d'une chaîne statique pour l'exemple
	new_node->next = NULL;

	// Utilise ft_lstdelone pour supprimer l'élément (avec del étant NULL)
	ft_lstdelone(new_node, NULL);

	return (0);
}*/