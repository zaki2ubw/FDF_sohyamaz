/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:02:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/10 22:44:27 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROT_H
# define PROT_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>
#include <fcntl.h>

# ifndef KEY_ESC
#  define KEY_ESC 65307
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1080
# endif

# ifndef OFFSET_X
#  define OFFSET_X WINDOW_WIDTH / 4
# endif

# ifndef OFFSET_Y
#  define OFFSET_Y WINDOW_HEIGHT / 4
# endif

# ifndef DEFAULT_ZOOM
#  define DEFAULT_ZOOM 30
# endif

# ifndef DEFAULT_Z_SCALE
#  define DEFAULT_Z_SCALE 0.5
# endif

# ifndef ISOM_ANGLE
#  define ISOM_ANGLE M_PI / 6
# endif

#define ERR_NULL_VALUE_DETECTED 1
#define ERR_VAL_ALLOC_FAILED 2
#define ERR_VAR_ALLOC_FAILED 3
#define ERR_IMAGE_ALLOC_FAILED 4
#define ERR_MAP_ALLOC_FAILED 5
#define ERR_SCALE_ALLOC_FAILED 6
#define ERR_CALC_ALLOC_FAILED 7
#define ERR_COLOR_ALLOC_FAILED 8
#define ERR_MLX_INIT_FAILED 9
#define ERR_MLX_NEW_WINDOW_FAILED 10
#define ERR_MLX_NEW_IMAGE_FAILED 11
#define ERR_MLX_GET_DATA_ADDR_FAILED 12
#define ERR_ZMAP_ALLOC_FAILED 13
#define ERR_ZVALUE_ALLOC_FAILED 14
#define ERR_SPLIT_FAILED 15
#define ERR_GNL_FAILED 16
#define ERR_COORD_ALLOC_FAILED 17
#define ERR_INIT_COORD_FAILED 18
#define ERR_ISOM_ALLOC_FAILED 19
#define ERR_INIT_ISOM_FAILED 20
#define ERR_GET_DATA_ADDR_FAILED 21

typedef struct s_structs
{
	struct s_map *map;
	struct s_3d	**coord;
	struct s_isom **isom;
	struct s_scale *scale;
	struct s_var *var;
	struct s_image *image;
	struct s_color *palette;
	struct s_calc *calc;
} t_structs;

typedef struct s_map
{
    int **z_map;
    int width;
    int height;
} t_map;

typedef struct s_3d
{
    int x;
    int y;
    int z;
} t_3d;

typedef struct s_isom
{
    int x;
    int y;
} t_isom;

typedef struct s_scale
{
    double zoom;
    double z_scale;
    int offset_x;
    int offset_y;
} t_scale;

typedef struct s_var
{
    void    *mlx;
    void    *win;
} t_var;

typedef struct s_image
{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_image;

typedef struct s_color
{
	int	clear;
	int	red;
	int	green;
	int blue;
}	t_color;

typedef struct s_calc
{
	int x;
	int	y;
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	err;
} t_calc;

//bresenham.c
int		set_sign(int start, int goal);
int		set_calc(t_structs *val, t_isom *st, t_isom *gl);
int		err_check_x(t_structs *val, t_calc *calc, t_isom *gl, int color);
int		err_check_y(t_structs *val, t_calc *calc, t_isom *gl, int color);
int		bresenham(t_structs *val, t_isom *st, t_isom *gl, int color);

//color.c
int		color_init(t_color *palette);

//draw.c
int		draw_loop(t_structs *val, int vt, int color);
void	draw_line(t_structs *val);

//event.c
int	close_window_esc(int keycode, t_structs *val);
int	close_window_cross(t_structs *val);

//image.c
void	create_window(t_structs *val);
int		set_var(t_var **var);
int		set_image(t_var *var, t_image *image);
void	pixel_put(t_structs *val, int x, int y, int color);

//init.c
void	init_structs(t_structs **val);
int		init_val(t_structs **val);
int		init_maps(t_structs *val);
int		init_mlx(t_structs *val);
int		init_modules(t_structs *val);
int		init_color(t_structs *val);

//map.c
int		count_column(char *line, char cut);
int		count_map_size(t_map **map, int fd);
void	check_map_size(t_structs *val, char *file, t_map **map);
int		convert_map(t_map **map, char **args, int count);
int		set_map(t_map **map, int fd);
int		init_z_map(t_map **map);
void	read_map(t_structs *val, char *file, t_map **map);

//mem_util.c
void	error_exit(t_structs **val, int error);
void	free_val(t_structs **val);
void	put_error(int error);
void	free_args(char *line, char **args);
void	free_z_map(int **z_map, int height);
void	free_coord(t_3d **coord, int height);
void	free_isom(t_isom **isom, int height);
void	free_elements(t_structs **val, int height);

//projection.c
int	init_coord(t_structs *val);
int	init_isom(t_structs *val);
void	set_scale(t_structs *val);
int	set_coord(t_structs *val);
int isom_x(t_3d coord, t_scale *scale);
int isom_y(t_3d coord, t_scale *scale);
int	trans_isom(t_structs *val);
void	check_limit(int target, int *min, int *max);
int	get_center_offset_x(t_structs *val);
int	get_center_offset_y(t_structs *val);
int	offset_image(t_structs *val);
void	projection(t_structs *val);

//wrappers.c
int draw_line_wrapper(void *ptr);

#endif
