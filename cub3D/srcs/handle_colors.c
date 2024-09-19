/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:04:23 by vschneid          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:20 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	finalize_color_parsing(t_parse_context *context)
{
	if (context->color_info->i != 3)
		color_error(context->cubed, context->line, context->fd);
}

void	parse_colors(t_cub *cubed, int *color, char *line, int fd)
{
	char			*start;
	char			*token;
	t_color_info	color_info;
	t_parse_context	context;

	start = ft_strchr(line, ' ');
	if (start == NULL)
		color_error(cubed, line, fd);
	start++;
	check_for_double_commas(cubed, start, fd, line);
	initialize_color_info(&color_info, color);
	context.cubed = cubed;
	context.color_info = &color_info;
	context.fd = fd;
	context.line = line;
	token = ft_strtok(start, ",");
	while (token != NULL)
	{
		if (context.color_info->i >= 3)
			color_error(context.cubed, context.line, context.fd);
		process_color_token(&context, token);
		token = ft_strtok(NULL, ",");
	}
	finalize_color_parsing(&context);
}

bool	is_color_line(t_cub *cubed, char *line, int fd)
{
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	if (line[0] == 'F' || line[0] == 'C')
		color_error(cubed, line, fd);
	return (false);
}

void	save_colors(t_cub *cubed, char *line, int fd)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		parse_colors(cubed, cubed->map_data->floor_color, line, fd);
		cubed->map_data->floor = (cubed->map_data->floor_color[0] << 16)
			| (cubed->map_data->floor_color[1] << 8)
			| cubed->map_data->floor_color[2];
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		parse_colors(cubed, cubed->map_data->ceiling_color, line, fd);
		cubed->map_data->ceiling = (cubed->map_data->ceiling_color[0] << 16)
			| (cubed->map_data->ceiling_color[1] << 8)
			| cubed->map_data->ceiling_color[2];
	}
}
