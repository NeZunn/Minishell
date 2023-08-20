/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:06:06 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/20 11:36:36 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "color.h"
# include "tokens.h"
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

// int         g_num_env_vars;
// extern char **  environ;
# define PATH_MAX 4096
# define LOGIN_NAME_MAX 256
# define N_ARGS 2560
# define MAX_ENV_VARS 10240

// Structure to hold tokens
typedef struct s_token
{
	int				type;
	char			*value;
	char			*cmd_path;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

// Structure to hold environment variables
typedef struct env_var_s
{
    char	*key;
    char	*value;
}	env_var_t;

typedef struct s_main
{
	int	nuclear_status; // exit status
	env_var_t	**env_vars;
	char		**envp;
}	t_main;

// extern env_var_t **g_env_vars;
extern t_main *g_main;

void		perror_color(char *str);
void		error_exit(char *str, bool is_perror);
void		exit_success(void);

char		*prompt_msg(char prompt[LOGIN_NAME_MAX + PATH_MAX + 20]);

void		init(char **envp);
void		init_signals(void);

bool		match_cmd(char *inpt, char *args[N_ARGS], char **envp);
char		*find_command_path(char *command, char **envp);
void		parse_input(char *input, char **envp);

void		add_env_vars(char *key, char *value);
void		modify_env_vars(char *key, char *value);
env_var_t	*find_env_vars(char *key);
int			find_env(char *key, char **envp);
char		*ft_getenv(char *key);
void		free_env_vars(void);
bool		flip_bool_env_vars(char *key);
// bool    print_env_vars();

env_var_t	**dup_darr(char **arr);
void		free_darr(env_var_t **arr);
void		free_jutsu(bool darr, char *key, char *value);

bool		execute_cd(char *args[N_ARGS], char **envp);
bool		execute_export(char **args);
bool		welcome_msg(void);

int			ft_snprintf(char *str, size_t size, const char *format, ...);
char		*ft_strtok(char *str, const char *delim);
void		*ft_malloc(size_t size);

// Token functions
t_token		*first_last_token(t_token *tokens, bool is_last);
t_token		*token_join(t_token *tokens, char *str);
t_token 	create_token(char *value, int type);
void		free_token(t_token *token);

char		check_type(char *str);
#endif