/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:18:41 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/16 17:44:34 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool  flip_bool_env_vars(char *key)
{
    bool tmp;

    tmp = !ft_atoi(find_env_vars(key)->value);
    modify_env_vars(key, ft_itoa(tmp));
    return (true);
}