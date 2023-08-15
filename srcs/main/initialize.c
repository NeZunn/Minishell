/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:21:02 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 09:08:10 by codespace        ###   ########.fr       */
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

void	init(void)
{
	printf("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n");
	printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
	printf("         Made with love by : \033[0;35msinlee\033[m and \033[0;35mwp\033[m\n");
	g_num_env_vars = 0;
	init_signals();
}
