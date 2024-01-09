/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:40:10 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:31 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	// Création de quelques éléments pour la liste chaînée
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
	{
		printf("Erreur d'allocation de mémoire.\n");
		return (1);
	}

	node1->content = "Premier élément";
	node1->next = NULL;

	node2->content = "Deuxième élément";
	node2->next = NULL;

	node3->content = "Troisième élément";
	node3->next = NULL;

	// Initialisation de la liste et ajout des éléments
	t_list *myList = node1;
	node1->next = node2;
	node2->next = node3;

	// Utilisation de ft_lstlast pour obtenir le dernier élément
	t_list *lastElement = ft_lstlast(myList);

	// Affichage du dernier élément
	if (lastElement)
	{
		printf("Dernier élément : %s\n", (char *)lastElement->content);
	}
	else
	{
		printf("La liste est vide.\n");
	}

	// Libération de la mémoire
	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/