/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_linked_list_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:48 by djin              #+#    #+#             */
/*   Updated: 2023/08/17 13:21:51 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token **add_token, t_token *tok)
{
	t_token	*prev_token;
\
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