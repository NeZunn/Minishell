/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:21:02 by codespace         #+#    #+#             */
/*   Updated: 2023/08/16 18:56:17 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	implement_tools(t_tools *tools)
// {
// 	tools->args = NULL;
// 	tools->paths = NULL;
// 	tools->simple_cmds = NULL;
// 	tools->lexer_list = NULL;
// 	tools->pwd = NULL;
// 	tools->old_pwd = NULL;
// 	tools->pipes = 0;
// 	tools->pid = NULL;
// 	tools->heredoc = false;
// 	tools->reset = false;
// }

static void init_env(void)
{
	int	i;

	i = -1;
	g_env_vars = malloc(sizeof(env_var_t *) * MAX_ENV_VARS);
	while (++i < MAX_ENV_VARS)
	{
		g_env_vars[i] = malloc(sizeof(env_var_t));
		g_env_vars[i]->key = NULL;
		g_env_vars[i]->value = NULL;
	}
	add_env_vars(ft_strdup("NUM_QUOTES"), ft_strdup("0"));
	add_env_vars(ft_strdup("QUOTES"), ft_strdup("0"));
}

void	init(void)
{
	// g_num_env_vars = 0;
	init_env();
	init_signals();
	welcome_msg();
}
