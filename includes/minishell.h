/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:36:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/16 23:08:17 by sinlee           ###   ########.fr       */
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
# include <stdbool.h>

# define PIPE 1
# define HERE_DOC 2
# define REDIR_IN 3
# define REDIR_OUT 4
# define AND 5
# define OR 6
# define DOUBLE_AND 7
# define OPEN_BRACKET 8
# define CLOSE_BRACKET 9

// int         g_num_env_vars;
// extern char **  environ;
# define PATH_MAX 4096
# define LOGIN_NAME_MAX 256
# define N_ARGS 2560
# define MAX_ENV_VARS 10240

// Structure to hold tokens
typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

// Structure to hold environment variables
typedef struct env_var_s
{
    char	*key;
    char	*value;
}	env_var_t;

extern env_var_t **g_env_vars;

void		perror_color(char *str);
void		error_exit(char *str, bool is_perror);
void		exit_success(void);

char		*prompt_msg(char prompt[LOGIN_NAME_MAX + PATH_MAX + 20]);

void		init(void);
void		init_signals(void);

bool		match_cmd(char *inpt, char *args[N_ARGS], char **envp);
char		*find_command_path(char *command, char **envp);
void		parse_input(char *input, char **envp);

void		add_env_vars(char *key, char *value);
env_var_t	*find_env_vars(char *key);
void		modify_env_vars(char *key, char *value);
void		free_env_vars(void);
bool		flip_bool_env_vars(char *key);
// bool    print_env_vars();

bool		execute_cd(char *args[N_ARGS], char **envp);
bool		execute_export(char **args);
bool		welcome_msg(void);

int			ft_snprintf(char *str, size_t size, const char *format, ...);

#endif