/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:18:19 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 16:37:16 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void perror_color(char *str)
{
	char msg[1024];

	ft_snprintf(msg, sizeof(msg), "%s%s%s", RED, str, CYAN);
	perror(msg);
	printf("%s", RESET_COLOR);
}

void	error_exit(char *str, bool is_perror)
{
	char *msg;

	msg = malloc(1024);
	ft_snprintf(msg, 1024, "%s%s%s", RED, str, RESET_COLOR);
	if (is_perror)
		perror(msg);
	else
		printf("%s", msg);
	free(msg);
	exit(errno);
}

void exit_success()
{
	printf("%sBELLA CIAO%s\n", BLUE_BOLD, RESET_COLOR);
	free_env_vars();
	exit(EXIT_SUCCESS);
}