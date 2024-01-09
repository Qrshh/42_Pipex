/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:30:25 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:10:01 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nb, size_t taille)
{
	void	*res;

	res = malloc(nb * taille);
	if (!res)
		return (NULL);
	ft_memset(res, 0, nb * taille);
	return (res);
}
/*
int	main(void)
{
	// Nombre d'éléments et taille de chaque élément
	size_t num_elements = 5;
	size_t element_size = sizeof(int);

	// Appel de ft_calloc pour allouer de la mémoire
	int *arr = (int *)ft_calloc(num_elements, element_size);

	if (arr)
	{
		// Affiche les éléments du tableau
		for (size_t i = 0; i < num_elements; i++)
		{
			printf("arr[%zu] = %d\n", i, arr[i]);
		}

		// Libère la mémoire allouée pour le tableau
		free(arr);
	}
	else
	{
		printf("Allocation de mémoire échouée.\n");
	}

	return (0);
}*/