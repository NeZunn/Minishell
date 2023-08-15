/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:01:17 by codespace         #+#    #+#             */
/*   Updated: 2023/08/14 14:40:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main file for minishell project, which is a recreation of the bash shell

#include "minishell.h"

void restore_terminal_settings(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

// Signal handler for Ctrl-C
void	sigint_handler(int signum)
{
	(void)signum; // Avoid "unused parameter" warning
	printf("\n"); // Print a newline after Ctrl-C
	rl_on_new_line();
	rl_replace_line("", 0); // Clear the current line
	rl_redisplay();         // Redisplay the prompt
}

// Signal handler for Ctrl-D
void ctrld(int signum)
{
    (void)signum; // Avoid "unused parameter" warning
    printf("\nExit Success\n");
    exit(EXIT_SUCCESS); // Exit the program on Ctrl-D
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 || argv[1])
		error_exit("Error: too many arguments\n", false);
	// rl_catch_signals = 0;
	cgetattr(STDIN_FILENO, &orig_termios);
    atexit(restore_terminal_settings);

    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
	signal(SIGINT, sigint_handler);   // Ctrl-C
	signal(SIGQUIT, SIG_IGN); // "Ctrl-\"
	init();
	while (1)
	{
		char *input = readline("\033[0;35mminishell$\033[0m ");
		if (!input)
			exit_success();
		add_history(input);
		if (input[0] != '\0')
			parse_input(input, envp);
		free(input);
	}
	return (0);
}
