/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_linked_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/23 08:16:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// adds a token to the front of the linked list
void	token_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;
	t_token *last_token;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (lst)
	{
		if (tmp)
		{
			last_token = find_last_token(tmp);
			last_token -> next = new;
			new -> prev = last_token;
		}
		else
			*lst = new;
	}
}

// find last token in linked list
t_token	*find_last_token(t_token *lst)
{
	t_token	*newnode;

	newnode = lst;
	while (newnode != NULL && newnode -> next != NULL)
		newnode = newnode -> next;
	return (newnode);
}

// creates a new token
t_token	*create_token(int type, t_token *tokens)
{
	tokens = malloc(sizeof(t_token));
	if (!tokens)
		return (NULL);
	tokens->type = type;
	tokens->cmd = NULL;
	tokens->next = NULL;
	tokens->prev = NULL;
	return (tokens);
}

// finds first or last token in linked list
t_token *first_last_token(t_token **tokens, bool is_last)
{
	if (!(*tokens))
		return (NULL);
	if (is_last)
	{
		while ((*tokens)->next)
			(*tokens) = (*tokens)->next;
		return ((*tokens));
	}
	else
	{
		while ((*tokens)->prev)
			(*tokens) = (*tokens)->prev;
		return ((*tokens));
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
