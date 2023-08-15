/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:21:28 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 07:00:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
# include <termio.h>
# include <termios.h>

void	sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_errno = 1;
}

void	init_signals(void)
{
	struct termios	termios_current;

	if (tcgetattr(STDIN_FILENO, &termios_current) == -1)
		error_exit("Tcgetattr failed\n", true);
	termios_current.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &termios_current) == -1)
		error_exit("Tcsetattr failed\n", true);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
