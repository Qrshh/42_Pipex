/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:08:13 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:30 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == 0)
		return ((char *)(str));
	if (n == 0)
		return (NULL);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "fdsfnabcreturneur";
	char	to_find[] = "abc";

	printf("%s", ft_strnstr(str, to_find, 3));
}*/