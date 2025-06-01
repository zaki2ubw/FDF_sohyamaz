/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:02:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/01 18:02:04 by sohyamaz         ###   ########.fr       */
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

#define ERR_STRUCTS_ALLOC_FAILURE 1
#define ERR_VAR_ALLOC_FAILURE 2
#define ERR_IMAGE_ALLOC_FAILURE 3
#define ERR_MAP_ALLOC_FAILURE 4
#define ERR_COORDI_ALLOC_FAILURE 5
#define ERR_ISOL_ALLOC_FAILURE 6
#define ERR_SCALE_ALLOC_FAILURE 7
#define ERR_MLX_ALLOC_FAILURE 8
#define ERR_LINE_ALLOC_FAILURE 9
#define ERR_INVALID_MAP 10

typedef struct s_structs
{
	struct s_map *map;
	struct s_3d	*coordinate;
	struct s_isol *isol;
	struct s_scale *scale;
	struct s_var *var;
	struct s_image *image;
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

typedef struct s_isol
{
    int x;
    int y;
} t_isol;

typedef struct s_scale
{
    float zoom;
    float z_scale;
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

//init.c
int	init_structs(t_structs **val);
int	init_mlx(t_var **var, t_image **image);
int	init_elements(t_map **map, t_3d **coordinate, t_isol **isol, t_scale **scale);
int	init_var(t_var **var, t_map **map);
void	init_image(t_var *var, t_map *map, t_image *image);

//map.c
void	read_map(char *file, t_map **map);
int	count_x(char *line, char cut);
int	count_grid(char *file, t_map **map);
int	init_z_map(t_map **map);
void	convert_map(t_map **map, char **args, int count);

//mem_util.c
void	error_exit(t_structs **val, int error);
void	free_val(t_structs **val, int error);
void	put_error(int error);
void	free_args(char **args);
void	free_z_map(int **z_map);

#endif
