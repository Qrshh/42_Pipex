/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:56:50 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 05:54:14 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
# include "../Libft/inc/libft.h"

typedef struct s_two_pid
{
    pid_t pid1;
    pid_t pid2;
    int first_fd;
    int second_fd;
}   t_two_pid;


int	check_input(int ac);
void    exec_command(char **arg_tab, char **path_tab);

#endif
