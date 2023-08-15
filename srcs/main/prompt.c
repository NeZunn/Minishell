/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 02:29:43 by codespace         #+#    #+#             */
/*   Updated: 2023/08/15 02:29:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *prompt_msg(char *username, char *cwd)
{
    char *prompt;

    prompt = ft_strjoin("\033[0;35m@%s %s-> %s%s%s $ ", username, RESET_COLOR, BLUE_BOLD, cwd, RESET_COLOR);
    return (prompt);
}