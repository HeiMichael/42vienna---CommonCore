/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:03:11 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 16:35:30 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stddef.h>		//NULL
# include <stdlib.h>		//exit
# include <stdio.h>			//printf
# include <unistd.h>		//write
# include <fcntl.h>			//open
# include <stdbool.h>		//bool

# define SCREEN_W		960
# define SCREEN_H		540
# define TILE_SIZE		64
# define FOV			60
# define PI_2			1.570796
# define PI				3.141593
# define PI_3			4.712389
# define ONE_DEGREE		0.017453
# define NUM_RAYS		60

typedef struct s_player
{
	double	player_x;
	double	player_y;
	double	angle;
}	t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_texture
{
	void	*img;
	int		*pixel;
	int		width;
	int		height;
}	t_texture;

typedef struct s_map
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				floor_color[3];
	int				ceiling_color[3];
	unsigned int	floor;
	unsigned int	ceiling;
}	t_map;

typedef struct s_map_data
{
	int	start_saving_map;
	int	floor_color_count;
	int	ceiling_color_count;
	int	map_index;
}	t_map_data;

typedef struct s_ray
{
	double	y;				//current pos of player in pixels
	double	x;
	double	off_x;			//offset in pixels
	double	off_y;
	double	cam_x;			//current pos of player in pixels
	double	cam_y;
	double	ver_x;			//vertical hit point in pixels
	double	ver_y;
	double	hor_x;			//hor hit point in pixels
	double	hor_y;
	double	ver_dist;		//distance player hor hit point
	double	hor_dist;		//distance player vert hit point
	double	distance;
	double	look;
	int		side;
	int		hit;
	int		map_x;			//current ray position in coordinates
	int		map_y;
	int		max_grid_x;		//max grid size
	int		max_grid_y;
	double	ray_angle;		//angle of ray
	int		tex_x;
	int		tex_y;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	int		coll_x;
	int		coll_y;
	int		coll_a;
	int		coll_b;
}	t_ray;

typedef struct s_cub
{
	void		*mlx_connection;
	void		*mlx_window;
	char		*name;
	char		**map;
	int			grid_x;
	int			grid_y;
	char		**pot;
	t_player	*player;
	t_ray		*ray;
	t_map		*map_data;
	t_img		img;
	t_texture	*textures;
}	t_cub;	

typedef struct s_color_info
{
	int	i;
	int	j;
	int	*color;
}	t_color_info;

typedef struct s_parse_context
{
	t_cub			*cubed;
	t_color_info	*color_info;
	int				fd;
	char			*line;
}	t_parse_context;

typedef struct s_map_inf
{
	t_cub	*cubed;
	char	**map;
	int		y;
	int		x;
	char	**extra_map;
	int		line_count;
}	t_map_inf;

//distance.c
double	calc_hor_distance(t_cub *cubed);
double	calc_ver_distance(t_cub *cubed);
void	side_decidion(t_cub *cubed, double ray_angle, double angle_diff);
void	compare_distance(t_cub *cubed, double ray_angle);
//events.c
int		is_collision(t_cub *cubed, double x, double y);
void	check_collision(t_cub *cubed, double *new_x, double *new_y);
void	calc_move(t_cub *cubed, double *new_x, double *new_y, int dec);
int		movement(int keysym, t_cub *cubed);
int		x_click(t_cub *cubed);

//free_and_exit.c
int		free_exit(t_cub *cubed, char *message);
//init.c
void	put_pixel_to_image(t_cub *cubed, int x, int y, int color);
void	loading_textures(t_cub *cubed);
void	init_mlx(t_cub *cubed);
void	init_map(t_cub *cubed, int map_height);
//main.c
void	init_cubed(t_cub *cubed);
int		render_and_events(t_cub *cubed);
int		main(int argc, char **argv);
//ray.c
double	check_angle(double ray_angle);
void	horizontal_intersection(t_cub *cubed, int *depth_of_field);
void	vertical_intersection(t_cub *cubed, int *depth_of_field);
void	vertical_check(t_cub *cubed, double ray_angle, int *depth_of_field);
void	horizontal_check(t_cub *cubed, double ray_angle, int *depth_of_field);
int		raycast(t_cub *cubed);
//utils.c
void	*allocate_memory(size_t type, size_t nbr_elements, t_cub cubed);
int		ft_isspace(int c);
char	*ft_strtok(char *str, const char *delim);
int		ft_strcmp(const char *s1, const char *s2);
int		get_row_length(char **map, int row_index);
double	check_angle(double ray_angle);
int		check_borders(t_cub *cubed);
// parse_map.c
void	handle_input_main(t_cub *cubed, char *map_file);
void	print_map(t_cub *cubed);
void	parse_texture_path(char **texture_path, char *line);
void	parse_colors(t_cub *cubed, int *color, char *line, int fd);
void	count_map_lines(t_cub *cubed, int *map_lines, char *map_file);
void	read_map_file(t_cub *cubed, char *map_file, int start_saving_map);
void	read_map_file_main(t_cub *cubed, char *map_file);
void	find_player(t_cub *cubed);
// save_map.c
void	save_texture_paths(t_cub *cubed, char *line, int fd);
void	save_colors(t_cub *cubed, char *line, int fd);
void	save_map(t_cub *cubed, char *line, int *map_index, int fd);
void	free_map_array(char **map, int line_count);
// check_map.c
void	check_file_extension(t_cub *cubed, char *map_file);
void	check_valid_map(t_cub *cubed, char *map_file);
char	**save_map_to_array(t_cub *cubed, const char *map_file,
			int *line_count);
bool	is_color_line(t_cub *cubed, char *line, int fd);
bool	valid_texture_paths(t_cub *cubed);
void	find_invalid_lines(t_cub *cubed, char *map_file);
void	find_max_map_values(t_cub *cubed, char *map_file);
void	find_invalid_chars(t_cub *cubed, int line_count, char **map);
void	find_open_spots(t_cub *cubed, char **map, int line_count,
			char **extra_map);
void	player_can_move(t_cub *cubed);
bool	correct_prefixes(char *line, int i);
void	color_error(t_cub *cubed, char *line, int fd);
void	check_for_double_commas(t_cub *cubed, char *start, int fd, char *line);
void	initialize_color_info(t_color_info *color_info, int *color);
void	process_color_token(t_parse_context *context, char *token);
void	process_line(t_cub *cubed, char *line, t_map_data *map_data, int fd);
void	check_left(t_map_inf *inf);
void	check_right(t_map_inf *inf);
void	check_top(t_map_inf *inf);
void	check_bottom(t_map_inf *inf);
// free_exit.c
void	free_mlx_textures(t_cub *cubed);
void	free_mlx(t_cub *cubed);
void	free_map(t_cub *cubed);
void	free_player(t_cub *cubed);
void	free_map_data(t_cub *cubed);
//walls.c
void	floor_and_ceiling(t_cub *cubed, int wall_start, int wall_end, int x);
void	render_wall(t_cub *cubed, t_texture *texture, int x);
void	render_walls(t_cub *cubed, int x);
void	check_tex_x(t_cub *cubed, t_texture *texture);

#endif
