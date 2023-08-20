/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:00:34 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/20 05:40:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(char *input, char **envp)
{
	t_token	*tokens;
	int		i;

	i = 0;
	tokens->value = (char **)malloc(sizeof(char *) * ft_strlen(input) + 1);
	tokens->value[i] = ft_strtok(input, " ");
	i++;
	while (tokens->value[i++])
	{
		tokens->type = check_type(tokens->value[i], tokens);
		tokens->next = tokens;
		tokens->prev = token_join(tokens, tokens->value[i]);
		tokens->value[i] = ft_strtok(NULL, " ");
	}
}
