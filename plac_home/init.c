#include "fdf.h"

int	color_init(t_color *scale)
{
	int	color;

	color = 0;
	color = (scale->clear << 24) | (scale->red << 16) | (scale->green << 8) | scale->blue;
	scale->clear = (scale->clear + 10) % 256;
	scale->red = (scale->red + 10) % 256;
	scale->green = (scale->green + 10) % 256;
	scale->blue = (scale->blue + 10) % 256;
	return (color);
}


