/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdemir <ozdemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:19:30 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/03 14:39:13 by ozdemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (ft_strchr_gnl(buffer) == 1)
	{
		ft_rest(buffer);
		dest = ft_join(dest, buffer);
	}
	while (ft_strchr_gnl(buffer) == 0 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(dest);
			return (NULL);
		}
		buffer[i] = '\0';
		dest = ft_join(dest, buffer);
	}
	return (dest);
}
/*
#include <fcntl.h>

int	main(void)
{
	int i;

	i = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	return (0);
}*/