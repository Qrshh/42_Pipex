/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:37:37 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:08:23 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
int	main(void)
{
	char *message = "Bonjour, le monde!";
	int fd = open("test", O_WRONLY | O_CREAT);
		// Utilisez 1 pour la sortie standard (stdout)

	ft_putstr_fd(message, fd);
	close (fd);
	return (0);
}*/