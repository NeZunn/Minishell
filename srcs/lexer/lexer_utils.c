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

char	check_type(char *str, t_token *tokens)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ')
			space_skip(str, &i);
		if (str[i] == '|' || || str[i] == '<' || str[i] == '>' || str[i] == '&'
			|| str[i] == '(' || str[i] == ')' || str[i] == ft_isdigit(str[i])
			|| str[i] == '$' || str[i] == '\'' || str[i] == '\"'|| str[i] == '\\'
			|| str[i] == '/' || str[i] == '{' || str[i] == '}')
			is_seperator(str, &i, &tokens);
		i++;
	}
}
