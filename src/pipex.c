/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:44 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 01:54:07 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* < file1 cmd1 | cmd2 > file2
	Cette commande redirige l'entree std du programme cmd1 pour lire dans le contenu du fichier file1
	cmd1 | cmd2 prend la sortie de cmd1 et la met en entree de cmd2 grace au pipe
	> file2 redirige la sortie std de cmd2 vers le fichier file2 ecrasant le contenu si il y a deja qq chose
*/

#include "../inc/pipex.h"

int	check_input(int ac, char **av)
{
	if (ac != 5)
        return (0);
    return(1);
}
int	main(int ac, char **av)
{
    /*besoin de deux forks pour pouvoir executer les deux commandes ensemble, 
    car on doit pas attendre que l'une soit finie avant que l'autre se lance*/

    int fd_tab[2];
    t_two_pid pidfork;

    if(!check_input(ac, av))
        return (EXIT_FAILURE);
    pidfork.first_fd = open(av[1], O_RDONLY);
    pidfork.second_fd = open(av[4], O_WRONLY | O_CREAT , 0666);

}
