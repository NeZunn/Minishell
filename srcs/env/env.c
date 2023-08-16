/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:41:03 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/16 17:43:49 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void add_env_vars(char *key, char *value)
{
    int i;

    i = 0;
    if (key == NULL)
        perror_color("Environment Variables Name CANNOT be NULL!");
    while (g_env_vars[i]->key != NULL && i < MAX_ENV_VARS)
        i++;
    if (i == MAX_ENV_VARS)
        perror_color("So... Maximum number of environment variables reached. ggwp?");
    g_env_vars[i]->key = key;
    g_env_vars[i]->value = value;
    // printf("Added %s=%s at index %d\n", key, value, i);
}

void modify_env_vars(char *key, char *value)
{
    env_var_t *tmp;

    tmp = find_env_vars(key);
    if (tmp != NULL)
    {
        free(tmp->value);
        tmp->value = value;
    }
}

env_var_t *find_env_vars(char *key)
{
    int i;

    i = 0;
    while (ft_strcmp(g_env_vars[i]->key, key) && i < MAX_ENV_VARS)
        i++;
    if (i == MAX_ENV_VARS)
    {
        perror_color("Dei. Your environment variables does not exist. Nearest IQ Checkup is 5km away tho.");
        return (NULL);
    }
    else
        return (g_env_vars[i]);
}

void free_env_vars(void)
{
    int i;

    i = -1;
    while (++i < MAX_ENV_VARS)
    {
        if (g_env_vars[i]->key != NULL)
            free(g_env_vars[i]->key);
        if (g_env_vars[i]->value != NULL)
            free(g_env_vars[i]->value);
    }
    printf("Environment variables freed.\n");
}