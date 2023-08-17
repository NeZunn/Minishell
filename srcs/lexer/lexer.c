/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:00:34 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/17 08:07:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(char *input, char **envp)
{
	t_token	*tokens;

	tokens->value = (char *)malloc(sizeof(char) * ft_strlen(input) + 1);
	tokens->value = ft_strcpy(tokens->value, input);
	tokens->value = ft_strtok(tokens->value, " ");
	while (tokens->value)
	{
		tokens->type = check_type(tokens->value, tokens);
		tokens = tokens->next;
		tokens->value = ft_strtok(NULL, " ");
	}
}
