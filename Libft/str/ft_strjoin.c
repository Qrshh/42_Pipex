/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:39:18 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:16 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		total;
	char	*res;

	total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

/*
int	main(void)
{
	const char *s1 = "Ozan";
	const char *s2 = "Demir";
	printf("%s", ft_strjoin(s1, s2));
}*/