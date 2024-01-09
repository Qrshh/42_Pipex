/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:19:03 by ozdemir           #+#    #+#             */
/*   Updated: 2024/01/08 16:06:02 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	exit_error(char *msg);
char	*path_join(char *path, char *bin);
int		open_file(char *file, int nb);
int		ft_str_chr(char *str, char c);
int		ft_str_ncmp(char *s1, char *s2, int n);

#endif
