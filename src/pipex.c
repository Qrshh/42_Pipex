/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:25:44 by abesneux          #+#    #+#             */
/*   Updated: 2023/12/08 04:00:24 by abesneux         ###   ########.fr       */
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

void    first_command(int first_fd, int wr_fd, char **av, char **envp) //wr_fd bout d'ecriture du pipe
{
    int i;
    i = 0;
    char **path_tab;
    char **arg_tab;
    char *final_path;
    /*On cherche la ligne qui contient tout les chemins d'acces au binaire (par exemple pour acceder a cat)*/
    while(ft_strncmp(envp[i], "PATH=", 5)) //si c'est 0 on trouve la bonne ligne
        i++;
    path_tab = ft_split(envp[i], ':'); //on split tout les binaires possibles
    arg_tab = ft_split(av[3], ' ');
    //Verifier si le binaire n'est pas dans le dossier courant
    if(access(arg_tab[0], X_OK) == 0) //verifier que la commande est executable (binaire == fichier executable de la commande en gros)
    {
        free(path_tab);
        execv(arg_tab[0], arg_tab);
    }
    else
    {
        i = 0;
        while(path_tab[i])
        {
            
        }
    }
}


int	main(int ac, char **av, char **envp)
{
    /*besoin de deux forks pour pouvoir executer les deux commandes ensemble, 
    car on doit pas attendre que l'une soit finie avant que l'autre se lance*/

    int fd_tab[2];
    pipe(fd_tab);

    t_two_pid pidfork;

    if(!check_input(ac, av))
        return (EXIT_FAILURE);
    pidfork.first_fd = open(av[1], O_RDONLY);
    pidfork.second_fd = open(av[4], O_WRONLY | O_CREAT , 0666);
    pidfork.pid1 = fork(); //creation premier fork
    

}
