/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:11:33 by djin              #+#    #+#             */
/*   Updated: 2023/08/16 22:31:56 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void	is_seperator(char *str, int *i, t_token *tok)
{
	if (str[*i] == '|')
	{
		tok->type = PIPE;
		(*i)++;
	}
	else if (str[*i] == '>')
	{
		tok->type = REDIR_OUT;
		(*i)++;
	}
	else if (str[*i] == '<')
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
	else if (str[*i] == '&')
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
	else if (str[*i] == '(' || str[*i] == ')')
	{
		if (str[*i] == '(')
			tok->type = OPEN_BRACKET;
		else
			tok->type = CLOSE_BRACKET;
		(*i)++;
	}
}
