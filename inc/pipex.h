/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:56:50 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 01:56:27 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_two_pid
{
    pid_t pid1;
    pid_t pid2;
    int first_fd;
    int second_fd;
}   t_two_pid;

# include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
# include "../Libft/inc/libft.h"

int	check_input(int ac, char **av);

#endif
