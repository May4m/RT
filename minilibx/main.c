#include <mlx.h>

int main(void)
{

	void	*mlx;

	mlx = mlx_init();
	void	*d = mlx_new_window(mlx, 500, 500, "ds");
	
	mlx_loop(mlx);
	return (0);
}
