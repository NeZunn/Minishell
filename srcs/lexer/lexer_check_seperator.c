/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_seperator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:27:44 by codespace         #+#    #+#             */
/*   Updated: 2023/08/17 14:08:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_seperator(char *str, int *i, t_token **tokens)
{
	if (str[*i] == '|')
	{
		if (str[*i + 1] == '|')
		{
			(*tokens)->type = OR;
			(*tokens)->next = (*tokens);
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = PIPE;
			(*tokens)->next = (*tokens);
			i++;
		}
	}
	else if(str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			(*tokens)->type = HERE_DOC;
			(*tokens)->next = (*tokens);
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = REDIR_IN;
			(*tokens)->next = (*tokens);
			i++;
		}
	}
	else if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			(*tokens)->type = REDIR_APPEND;
			(*tokens)->next = (*tokens);
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = REDIR_OUT;
			(*tokens)->next = (*tokens);
			i++;
		}
	}
	else if (str[*i] == '(' || str[*i] == ')' || str[*i] == '{' || str[*i] == '}')
	{
		if (str[*i] == '(')
			(*tokens)->type = OPEN_BRACKET;
		else if (str[*i] == ')')
			(*tokens)->type = CLOSE_BRACKET;
		else if (str[*i] == '{')
			(*tokens)->type = OPEN_BRACE;
		(*tokens)->next = (*tokens);
		else
			(*tokens)->type = CLOSE_BRACE;
		(*tokens)->next = (*tokens);
		(*i)++;
	}
	else if (str[*i] == '\\')
	{
		(*tokens)->type = BACKSLASH;
		(*tokens)->next = (*tokens);
		(*i)++;
	}
	else if (str[*i] == '&')
	{
		if (str[*i + 1] == '&')
		{
			(*tokens)->type = AND;
			(*tokens)->next = (*tokens);
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = AMPERSAND;
			(*tokens)->next = (*tokens);
			i++;
		}
	}
	else if (str[*i] == '$')
	{
		(*tokens)->type = DOLLAR;
		(*tokens)->next = (*tokens);
		(*i)++;
	}
	else if (str[*i] == '\'')
	{
		(*tokens)->type = QUOTE;
		(*tokens)->next = (*tokens);
		(*i)++;
	}
	else if (str[*i] == '\"')
	{
		(*tokens)->type = DQUOTE;
		(*tokens)->next = (*tokens);
		(*i)++;
	}
}
