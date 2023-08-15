/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:51:29 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 04:12:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool execute_cd(char *args[N_ARGS], char **envp)
{
    if (chdir(args[1]) != 0)
        perror_color("cd");
    return (true);
}