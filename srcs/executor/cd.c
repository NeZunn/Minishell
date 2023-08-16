/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:51:29 by codespace         #+#    #+#             */
/*   Updated: 2023/08/16 16:17:44 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool execute_cd(char *args[N_ARGS], char **envp)
{
    char *path;

    if (args[1] == NULL || !ft_strcmp(args[1], "~"))
        path = ft_strdup(getenv("HOME"));
    else
        path = ft_strdup(args[1]);
    if (chdir(path) != 0)
        perror_color("cd");
    free(path);
    return (true);
}