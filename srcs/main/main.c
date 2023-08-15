/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:01:17 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 07:04:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main file for minishell project, which is a recreation of the bash shell

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*username;
	char	cwd[PATH_MAX];
	char	*input;
	char	prompt[LOGIN_NAME_MAX + PATH_MAX + 20];

	if (argc != 1 || argv[1])
		error_exit("Error: too many arguments\n", false);
	init();
	while (1)
	{
		username = getenv("USER");
		if (username == NULL)
		{
			perror("getenv");
			exit(EXIT_FAILURE);
		}
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			exit(EXIT_FAILURE);
		}
		ft_snprintf(prompt, sizeof(prompt), "\033[0;35m@%s %s-> %s%s%s $ %s",
			username, RESET_COLOR, BLUE_BOLD, cwd, RESET_COLOR, CYAN);
		input = readline(prompt);
		if (!input)
			exit_success();
		add_history(input);
		if (input[0] != '\0')
			parse_input(input, envp);
		free(input);
	}
	return (0);
}
