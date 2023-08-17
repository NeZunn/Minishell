/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_linked_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/17 08:13:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token **add_token, t_token *tok)
{
	t_token	*prev_token;

	if (!(*add_token))
	{
		*add_token = tok;
		return ;
	}
	prev_token = *add_token;
	while (prev_token->next)
		prev_token = prev_token->next;
	prev_token->next = tok;
	tok->prev = prev_token;
}

t_token *first_last_token(t_token *tokens, bool is_last)
{
	if (!tokens)
		return (NULL);
	if (is_last)
	{
		while (tokens->next)
			tokens = tokens->next;
		return (tokens);
	}
	else
	{
		while (tokens->prev)
			tokens = tokens->prev;
		return (tokens);
	}
}

t_token create_token(char *value, int type)
{
	t_token	token;

	token.value = value;
	token.type = type;
	token.next = NULL;
	token.prev = NULL;
	token.cmd_path = NULL;
	return (token);
}

void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	if (token->cmd_path)
		free(token->cmd_path);
	free(token);
}
