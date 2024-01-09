/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:35:25 by ozdemir           #+#    #+#             */
/*   Updated: 2023/12/04 13:08:14 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char c = 'A'; // Caractère que vous souhaitez écrire
	int fd = 1;   // Utilisez 1 pour la sortie standard (stdout)

	ft_putchar_fd(c, fd);

	return (0);
}*/