/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:11:31 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:09:22 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
/*
void	delete_element(void *content)
{
	free(content);
}

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

	node1->content = strdup("Premier élément");
		// Utilisation de strdup pour allouer de la mémoire pour la chaîne
	node1->next = NULL;

	node2->content = strdup("Deuxième élément");
	node2->next = NULL;

	node3->content = strdup("Troisième élément");
	node3->next = NULL;

	// Initialisation de la liste et ajout des éléments
	t_list *myList = node1;
	node1->next = node2;
	node2->next = node3;

	// Utilisation de ft_lstclear pour vider la liste

	ft_lstclear(&myList, delete_element);
	
	return (0);
}*/