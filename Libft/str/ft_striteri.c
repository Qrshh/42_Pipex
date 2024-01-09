/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:13:59 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:13:13 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	print_char_with_index(unsigned int index, char *c)
{
	printf("Character at index %u: %c\n", index, *c);
}

int	main(void)
{
	char s[] = "Hello, World!";

	ft_striteri(s, print_char_with_index);

	return (0);
}*/