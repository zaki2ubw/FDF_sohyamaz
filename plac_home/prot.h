#ifndef PROT_H
# define PROT_H

#include "gnl.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>

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

#endif
