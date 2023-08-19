/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/19 05:55:16 by codespace        ###   ########.fr       */
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

typedef struct oppenheimer
{
	int	nuclear_status; // exit status
	env_var_t	**env_vars;
}	t_oppenheimer;

// extern env_var_t **g_env_vars;
extern t_oppenheimer g_oppenheimer;

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
char		*ft_strtok(char *str, const char *delim);

// Token functions
t_token		*first_last_token(t_token *tokens, bool is_last);
t_token		*token_join(t_token *tokens, char *str);
t_token 	create_token(char *value, int type);
void		free_token(t_token *token);
char		check_type(char *str);
void		is_symbol(char *str, int *i, t_token **tokens)
void		space_skip(char *str, int *i)
#endif