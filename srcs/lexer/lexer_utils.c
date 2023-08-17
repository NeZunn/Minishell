/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:11:33 by djin              #+#    #+#             */
/*   Updated: 2023/08/17 08:08:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

char	check_type(char *str, t_token tokens)
{
	int	i;

	i = 0;
	while(str[i])
	{
		is_seperator(str, &i, &tokens);
		is_seperator2(str, &i, &tokens);
		keyword(str, &i, &tokens);
	}
}



void	keyword(char *str, int *i, t_token *tok)
{
	if (str[*i] == '$')
	{
		tok->type = DOLLAR_SIGN;
		(*i)++;
	}
}

void	is_seperator(char *str, int *i, t_token *tok)
{
	if (str[*i] == '|')
	{
		tok->type = PIPE;
		(*i)++;
	}
	if (str[*i] == '>')
	{
		tok->type = REDIR_OUT;
		(*i)++;
	}
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			tok->type = HERE_DOC;
			(*i) += 2;
		}
		else
		{
			tok->type = REDIR_IN;
			(*i)++;
		}
	}
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			tok->type = REDIR_OUT_APPEND;
			(*i) += 2;
		}
		else
		{
			tok->type = REDIR_IN;
			(*i)++;
		}
	}
}

void	is_seperator2(char *str, int *i, t_token *tok)
{
		if (str[*i] == '&')
	{
		if (str[*i + 1] == '&')
		{
			tok->type = DOUBLE_AND;
			(*i) += 2;
		}
		else
		{
			tok->type = AND;
			(*i)++;
		}
	}
	if (str[*i] == '(' || str[*i] == ')')
	{
		if (str[*i] == '(')
			tok->type = OPEN_BRACKET;
		else
			tok->type = CLOSE_BRACKET;
		(*i)++;
	}
}
