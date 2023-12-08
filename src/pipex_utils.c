/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:38:57 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 05:36:14 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_tab(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}

void    exec_command(char **arg_tab, char **path_tab)
{
    char *final_path;
    char **path;
    int i;

    i = -1;
    final_path = malloc(1);
    while(path[++i])
    {
        final_path = ft_realloc(final_path, ft_strlen(path[i]) + ft_strlen(arg_tab[0]) + 2);
        ft_strcat(final_path, path[i]);
        ft_strcat(final_path, arg_tab[0]);
        if(access(final_path, X_OK) == 0)
        {
            free_tab(path_tab);
            execv(final_path, arg_tab);
        }
    }
    free_tab(path);
    free(final_path);
    perror("");
}
