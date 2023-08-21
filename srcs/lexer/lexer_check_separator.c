/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_separator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:27:44 by codespace         #+#    #+#             */
/*   Updated: 2023/08/21 12:57:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	 is_symbol(char *str, int *i, t_token *tokens)
{
	if (str[*i] == '|')
	{
		if (str[*i + 1] == '|')
		{
			(tokens)->type = OR;
			tokens->cmd = ft_strdup("||");
			(*i) += 2;
		}
		else
		{
			(tokens)->type = PIPE;
			tokens->cmd = ft_strdup("|");
			(*i)++;
		}
	}
	else if(str[*i] == '<' || str[*i] == '>')
	{
		if (str[*i + 1] == '<' || str[*i] == '<')
		{
			if (str[*i] == '<')
			{
				(tokens)->type = REDIR_IN;
				tokens->cmd = ft_strdup("<");
				(*i)++;
			}
			else
			{
				(tokens)->type = HERE_DOC;
				tokens->cmd = ft_strdup("<<");
				(*i) += 2;
			}
		}
		else if (str[*i + 1] == '>' || str[*i] == '>')
		{
			if (str[*i] == '>')
			{
				(tokens)->type = REDIR_OUT;
				tokens->cmd = ft_strdup(">");
				(*i)++;
			}
			else
			{
				(tokens)->type = REDIR_OUT_APPEND;
				tokens->cmd = ft_strdup(">>");
				(*i) += 2;
			}
		}
	}
	else if (str[*i] == '(' || str[*i] == ')' || str[*i] == '{' || str[*i] == '}')
	{
		if (str[*i] == '(')
		{
			(tokens)->type = OPEN_BRACKET;
			tokens->cmd = ft_strdup("(");
		}
		else if (str[*i] == ')')
		{
			(tokens)->type = CLOSE_BRACKET;
			tokens->cmd = ft_strdup(")");
		}
		else if (str[*i] == '{')
		{
			(tokens)->type = OPEN_BRACE;
			tokens->cmd = ft_strdup("{");
		}
		else
		{
			(tokens)->type = CLOSE_BRACE;
			tokens->cmd = ft_strdup("}");
		}
		(*i)++;
	}
	else if (str[*i] == '&')
	{
		if (str[*i + 1] == '&')
		{
			(tokens)->type = DOUBLE_AND;
			tokens->cmd = ft_strdup("&&");
			(*i) += 2;
		}
		else
		{
			(tokens)->type = ANDPARSEN; //ggwp, autolose, next game
			tokens->cmd = ft_strdup("&");
			i++;
		}
	}
	else if (str[*i] == '$')
	{
		(tokens)->type = DOLLAR; // financial issue?
		tokens->cmd = ft_strdup("$");
		(*i)++;
	}
	else if (str[*i] == '\'' || str[*i] == '\"')
	{
		if (str[*i] == '\'')
		{
			(tokens)->type = BOO_NO_EXPANSION;
			(tokens)->cmd = ft_strdup("\'");
		}
		else
		{
			(tokens)->type = DOMESTIC_EXPANSION;
			(tokens)->cmd = ft_strdup("\"");
		}
		(*i)++;
	}
	tokens = token_join(tokens, tokens->type);
	printf("%p\n", tokens);
	(tokens) = (tokens)->next;
}

void	is_word(char *str, int *i, t_token *tokens)
{
	int	j;

	j = 0;
	while (str[*i + j] && str[*i + j] != ' ' && str[*i + j] != '|'
		&& str[*i + j] != '<' && str[*i + j] != '>' && str[*i + j] != '&'
		&& str[*i + j] != '(' && str[*i + j] != ')' && str[*i + j] != '$'
		&& str[*i + j] != '\'' && str[*i + j] != '\"' && str[*i + j] != '\\'
		&& str[*i + j] != '/' && str[*i + j] != '{' && str[*i + j] != '}')
		j++;
	(tokens)->type = WORD;
	(tokens)->cmd = ft_substr(str, *i, j);
	tokens = token_join(tokens, WORD);
	printf("%p\n", tokens);
	(*i) += j;
	(tokens) = (tokens)->next;
}