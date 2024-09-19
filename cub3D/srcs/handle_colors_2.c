/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:34:09 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:26 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	color_error(t_cub *cubed, char *line, int fd)
{
	free(line);
	close(fd);
	free_exit(cubed, "Error\nInvalid color format.\n");
}

void	check_for_double_commas(t_cub *cubed, char *start, int fd, char *line)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if (start[i] == ',' && start[i + 1] == ',')
			color_error(cubed, line, fd);
		i++;
	}
}

void	initialize_color_info(t_color_info *color_info, int *color)
{
	color_info->i = 0;
	color_info->j = 0;
	color_info->color = color;
	while (color_info->j < 3)
		color_info->color[color_info->j++] = -1;
}

void	process_color_token(t_parse_context *context, char *token)
{
	int		value;
	char	*c;
	size_t	len;

	while (ft_isspace((unsigned char)*token))
		token++;
	len = ft_strlen(token);
	if (len > 0 && (token[len - 1] == '\n' || token[len - 1] == '\r'))
		token[len - 1] = '\0';
	if (*token == '\0')
		color_error(context->cubed, context->line, context->fd);
	c = token;
	while (*c)
	{
		if (!ft_isdigit((unsigned char)*c))
			color_error(context->cubed, context->line, context->fd);
		c++;
	}
	value = ft_atoi(token);
	if (value < 0 || value > 255)
		color_error(context->cubed, context->line, context->fd);
	context->color_info->color[context->color_info->i] = value;
	context->color_info->i++;
}
