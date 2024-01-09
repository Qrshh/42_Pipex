/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:49:49 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:08:17 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}
/*
int	main(void)
{
	char *message = "Bonjour, le monde!";
	int fd = 1;

	ft_putendl_fd(message, fd);
	return (0);
}*/