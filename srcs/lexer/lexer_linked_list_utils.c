/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_linked_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/18 17:47:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_join(t_token *tokens, char *str)
{
	t_token	*new_token;

	new_token = create_token(str, 0);
	if (!new_token || !tokens)
		return (NULL);
	tokens -> next = new_token;
	new_token -> prev = tokens;
	return (new_token); 
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
	t_token tokens;

	tokens = malloc(sizeof(t_token));
	if (!tokens)
		return (NULL);
	tokens->value = value;
	tokens->type = type;
	tokens->next = NULL;
	tokens->prev = NULL;
}

void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	if (token->cmd_path)
		free(token->cmd_path);
	free(token);
}
