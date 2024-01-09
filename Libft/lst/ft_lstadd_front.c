/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:47:39 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:20 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
	// Création de quelques éléments pour la liste chaînée
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
	{
		printf("Erreur d'allocation de mémoire.\n");
		return 1;
	}

	node1->content = "Premier élément";
	node1->next = NULL;

	node2->content = "Deuxième élément";
	node2->next = NULL;

	node3->content = "Troisième élément";
	node3->next = NULL;

	// Initialisation de la liste et ajout des éléments
	t_list *myList = NULL;
	ft_lstadd_front(&myList, node1);
	ft_lstadd_front(&myList, node2);
	ft_lstadd_front(&myList, node3);

	// Parcours et affichage de la liste pour vérification
	t_list *current = myList;
	while (current != NULL)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}

	printf("NULL\n");

	// Libération de la mémoire
	free(node1);
	free(node2);
	free(node3);

	return 0;
}*/