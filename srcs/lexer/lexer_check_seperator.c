/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_seperator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:27:44 by codespace         #+#    #+#             */
/*   Updated: 2023/08/18 15:24:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_symbol(char *str, int *i, t_token **tokens)
{
	if (str[*i] == '|')
	{
		if (str[*i + 1] == '|')
		{
			(*tokens)->type = OR;
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = PIPE;
			i++;
		}
	}
	else if(str[*i] == '<' || str[*i] == '>')
	{
		if (str[*i + 1] == '<' || str[*i] == '<')
		{
			if (str[*i] == '<')
			{
				(*tokens)->type = REDIR_IN;
				i++;
			}
			else
			{
				(*tokens)->type = HERE_DOC;
				(*i) += 2;
			}
		}
		else if (str[*i + 1] == '>' || str[*i] == '>')
		{
			if (str[*i] == '>')
			{
				(*tokens)->type = REDIR_OUT;
				i++;
			}
			else
			{
				(*tokens)->type = REDIR_APPEND;
				(*i) += 2;
			}
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
		else
			(*tokens)->type = CLOSE_BRACE;
		(*i)++;
	}
	else if (str[*i] == '&')
	{
		if (str[*i + 1] == '&')
		{
			(*tokens)->type = AND;
			(*i) += 2;
		}
		else
		{
			(*tokens)->type = AMPERSAND;
			i++;
		}
	}
	else if (str[*i] == '$')
	{
		(*tokens)->type = DOLLAR;
		(*i)++;
	}
	else if (str[*i] == '\'' || str[*i] == '\"')
	{
		if (str[*i] == '\'')
		{
			(*tokens)->type = QUOTE;
		}
		else
		{
			(*tokens)->type = DQUOTE;
		}
		(*i)++;
	}
	(*tokens)->next = (*tokens);
}

void	is_word(char *str, int *i, t_token **tokens)
{
	int		j;
	char	*word;

	j = 0;
	while (str[*i + j] && str[*i + j] != ' ' && str[*i + j] != '|' && str[*i + j] != '<'
		&& str[*i + j] != '>' && str[*i + j] != '&'
		&& str[*i + j] != '(' && str[*i + j] != ')' && str[*i + j] != '$' 
		&& str[*i + j] != '\'' && str[*i + j] != '\"'&& str[*i + j] != '\\'
		&& str[*i + j] != '/' && str[*i + j] != '{' && str[*i + j] != '}')
		j++;
	word = ft_substr(str, *i, j);
	(*tokens)->type = WORD;
	(*tokens)->content = word;
	(*tokens)->next = (*tokens);
	(*i) += j;
}