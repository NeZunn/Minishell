/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:00:34 by sinlee            #+#    #+#             */
/*   Updated: 2023/09/03 14:04:10 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del(void *content)
{
	free(content);
}

void	parse_input(char *input, char **envp)
{
	t_token **tokens;
	int		i;
	int		j;
	int		count_words;

	i = 0;
	j = 0;
	tokens = (t_token **)malloc(sizeof(t_token *));
	(*tokens) = NULL;
	// printf("tokens->firstaddress %p\n", (*tokens));
	while (input[i])
	{
		count_words = 0;
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		if (ft_isalpha(input[i]) == true && input[i] != '\0')
		{
			j = i;
			while (ft_isalpha(input[i]) == true && input[i] != '\0')
			{
				i++;
				count_words++;
			}
			(*tokens) = add_tokens(*tokens, ft_substr(input, j, count_words), WORD);
		}
		if (ft_symbol(input[i]) == true && input[i] != '\0')
			is_symbol(input, &i, tokens);
		if (ft_isdigit(input[i]) == true && input[i] != '\0')
		{
			j = i;
			while (ft_isdigit(input[i]) == true && input[i] != '\0')
			{
				i++;
				count_words++;
			}
			(*tokens) = add_tokens(*tokens, ft_substr(input, j, count_words), DIGIT);
		}
		else
			i++;
	}
	// print_stack(*tokens);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$: ");
		parse_input(input, envp);
		free(input);
	}
	return (0);
}
