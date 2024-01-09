/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:28:31 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:08:09 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	// Crée un nouvel élément de liste avec du contenu
	int value = 42;
	t_list *new_node = ft_lstnew(&value);

	if (new_node)
	{
		// Affiche le contenu de la nouvelle liste
		printf("Content: %d\n", *(int *)(new_node->content));

		// Libère la mémoire allouée pour la nouvelle liste
		free(new_node);
	}
	else
	{
		printf("Échec de création de la nouvelle liste.\n");
	}

	return (0);
}*/