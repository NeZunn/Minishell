/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:58:35 by codespace         #+#    #+#             */
/*   Updated: 2023/08/16 17:21:45 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command_path(char *command, char **envp)
{
	char	*path_env;
	char	*path;
	char	*token;
    char    full_path[PATH_MAX];

	if ((command[0] == '.' && command[1] == '/' && !access(command+2, X_OK)))
		return (ft_strdup(command+2));
	if (!access(command, X_OK))
		return (ft_strdup(command));
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	path = ft_strdup(path_env);
	token = strtok(path, ":");
	while (token != NULL)
	{
		ft_snprintf(full_path, PATH_MAX, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (ft_strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

bool	match_cmd(char *inpt, char *args[N_ARGS], char **envp)
{
	if (!ft_strcmp(inpt, "exit"))
		exit_success();
	else if (!ft_strcmp(inpt, "cd"))
		execute_cd(args, envp);
	else if (!ft_strcmp(inpt, "fancy"))
		welcome_msg();
	else if (!ft_strcmp(inpt, "quotes"))
		flip_bool_env_vars("QUOTES");
	// else if (ft_strcmp(inpt, "export") == 0)
	// {
	    // if (args[1] != NULL)
        // {
        //     if(execute_export(args) == true)
        //         printf("Environment variable exported successfully.\n");
		// 	return (true);
        // }
        // else
        //     print_env_vars();
	// }
	// else if (ft_strcmp(inpt, "unset"))
	//     ft_unset(envp);
	else
		return (false);
}
