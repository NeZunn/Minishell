 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:11:33 by djin              #+#    #+#             */
/*   Updated: 2023/08/17 13:03:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space_skip(char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
}

void	check_type(char *input, t_token *tokens)
{
	int	i;

	i = 0;
	while (input[i])
	{
		tokens = create_token(0);
		if (ft_isalpha(input[i]) == true)
			is_word(input, &i, tokens);
		else if (input[i] == ' ')
			space_skip(input, &i);
		else if (input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i] == '&'
			|| input[i] == '(' || input[i] == ')' || input[i] == '$' 
			|| input[i] == '\'' || input[i] == '\"'|| input[i] == '\\'
			|| input[i] == '/' || input[i] == '{' || input[i] == '}')
			is_symbol(input, &i, tokens);
	}
}
