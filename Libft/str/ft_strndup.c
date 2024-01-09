/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:56:36 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/20 12:49:22 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(char *str, unsigned int n)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		dest[i] = *str;
		i++;
		str++;
	}
	dest[n] = 0;
	return (dest);
}
