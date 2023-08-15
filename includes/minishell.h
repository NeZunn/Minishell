/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:49:28 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/15 09:22:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "color.h"
# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>

int		    g_errno;
int         g_num_env_vars;
extern char **  environ;
# define PATH_MAX 4096
# define LOGIN_NAME_MAX 256
# define N_ARGS 256
#define MAX_ENV_VARS 1024

// Structure to hold environment variables
typedef struct {
    char *name;
    char *value;
} env_var_t;

env_var_t env_vars[MAX_ENV_VARS];

void    perror_color(char *str);
void	error_exit(char *str, bool is_perror);
void	exit_success(void);

void	init(void);
void	init_signals(void);

bool	match_cmd(char *inpt, char *args[N_ARGS], char **envp);
char	*find_command_path(char *command, char **envp);
void	parse_input(char *input, char **envp);
bool    print_env_vars();

bool    execute_cd(char *args[N_ARGS], char **envp);
bool    execute_export(char **args);

int		ft_snprintf(char *str, size_t size, const char *format, ...);

#endif