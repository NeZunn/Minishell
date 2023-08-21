/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_linked_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/21 12:56:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_join(t_token *tokens, int type)

{
	t_token	*new_token;

	new_token = tokens;
	if (!new_token)
		return (NULL);
	if (!tokens)
		return (new_token);
	tokens->next = new_token;
	new_token -> prev = tokens;
	return (new_token);
}

t_token	*create_token(int type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->cmd = NULL;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

t_token *first_last_token(t_token *tokens, bool is_last)
{
	if (!tokens)
		return (NULL);
	if (is_last)
	{
		while (tokens->next)
		{
			tokens = tokens->next;
		}
		return (tokens);
	}
	else
	{
		while (tokens->prev != NULL)
		{
			tokens = tokens->prev;
		}
		return (tokens);
	}
}

void	ft_lstclear_token(t_token **lst, void (*del)(void *))
{
	t_token	*newnode;
	t_token	*prevnode;

	if (!lst || !del)
		return ;
	prevnode = NULL;
	newnode = *lst;
	while (newnode->next != NULL)
	{
		prevnode = newnode;
		newnode = newnode->next;
		del(prevnode -> cmd);
		free(prevnode);
	}
	*lst = newnode;
}
