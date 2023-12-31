/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:08:08 by sinlee            #+#    #+#             */
/*   Updated: 2023/08/16 15:11:03 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

bool welcome_msg(void)
{
	printf("%s███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n", MAGENTA_BOLD);
	printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
	printf("%s         Made with love by : \033[0;35msinlee\033[m and \033[0;35mwp\033[m\n", WHITE);
    return (true);
}