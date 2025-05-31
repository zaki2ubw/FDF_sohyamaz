// test.c
#include "mlx.h"

int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 400, 300, "Hello MLX");
    mlx_loop(mlx);
    return 0;
}

