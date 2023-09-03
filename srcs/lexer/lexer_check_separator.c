/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_separator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:27:44 by codespace         #+#    #+#             */
/*   Updated: 2023/09/03 17:04:38 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_symbol(char input)
{
	if (input == '|' || input == '|' || input == '<' || input == '>' || input == '(' || input == ')'
		|| input == '{' || input == '}' || input == '&' || input == '$' || input == '\'' || input == '\"'
		|| input == '@' || input == '!' || input == '#' || input == '%' || input == '^' || input == '*'
		|| input == '-' || input == '+' || input == '=' || input == '?' || input == '/' || input == ':'
		|| input == '.' || input == '[' || input == ']' || input == '_')
		return (true);
	else
		return (false);
}

void	is_symbol(char *input, int *i, t_token **tokens)
{
	int		count_words;

	count_words = 0;
	if (input[*i] == '|')
	{
		if (input[*i + 1] == '|')
		{
			count_words = 2;
			(*tokens) = add_tokens(*tokens, "||", OR);
		}
		else
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "|", PIPE);
		}
	}
	if (input[*i] == '<' || input[*i] == '>')
	{
		if (input[*i + 1] == '<' && input[*i] == '<')
		{
			count_words = 2;
			(*tokens) = add_tokens(*tokens, "<<", HERE_DOC);
		}
		else if (input[*i + 1] == '>' && input[*i] == '>')
		{
			count_words = 2;
			(*tokens) = add_tokens(*tokens, ">>", REDIR_OUT_APPEND);
		}
		else if (input[*i] == '>')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, ">", REDIR_OUT);
		}
		else if (input[*i] == '<')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "<", REDIR_IN);
		}
	}
	if (input[*i] == '(' || input[*i] == ')' || input[*i] == '{' || input[*i] == '}')
	{
		if (input[*i] == '(')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "(", OPEN_BRACKET);
		}
		else if (input[*i] == ')')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, ")", CLOSE_BRACKET);
		}
		else if (input[*i] == '{')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "{", OPEN_BRACE);
		}
		else if (input[*i] == '}')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "}", CLOSE_BRACE);
		}
	}
	if (input[*i] == '[' || input[*i] == ']')
	{
		if (input[*i] == '[')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "[", OPEN_SQUARE_BRACKET);
		}
		else if (input[*i] == ']')
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "]", CLOSE_SQUARE_BRACKET);
		}
	}
	if (input[*i] == '&')
	{
		if (input[*i + 1] == '&' && input[*i] == '&')
		{
			count_words = 2;
			(*tokens) = add_tokens(*tokens, "&&", DOUBLE_AND);
		}
		else
		{
			count_words = 1;
			(*tokens) = add_tokens(*tokens, "&", ANDPARSEN);
		}
	}
	if (input[*i] == '$' || input[*i] == '\'' || input[*i] == '\"' || input[*i] == '!'
	|| input[*i] == '@' || input[*i] == '#' || input[*i] == '%' || input[*i] == '^'
	|| input[*i] == '*' || input[*i] == '-' || input[*i] == '_' || input[*i] == '+'
	|| input[*i] == '=' || input[*i] == '+' || input[*i] == ':' || input[*i] == '?'
	|| input[*i] == '.' || input[*i] == ',' || input[*i] == '/')
	{
		count_words = 1;
		(*tokens) = add_tokens(*tokens, ft_substr(input, *i, 1), ft_checksymb(input[*i]));
	}
	*i += count_words;
}
