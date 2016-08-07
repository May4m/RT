
#include "matrix.h"
#include <stdio.h>

void print(t_matrix *a)
{
	printf("printing %ix%i matrix..\n\n", a->rows, a->cols);
	int	i, j;

	i = 0;
	if (a->mat == NULL)
		printf("NULL matrix...");
	while (i < a->rows)
	{
		j = 0;
		while (j < a->cols)
		{
			printf("%f ", a->mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------------------------------------\n\n\n");
}

int	main()
{
	t_matrix	mat0 = new_mat(2, 4, 4.3);
	print(&mat0);
	t_matrix	mat1 = transpose_mat(&mat0);

	print(&mat1);
	t_matrix44 mat2 = new_mat44(4.4);
	print(&mat2);
	kill_matrix(&mat2);

	t_matrix44	m = new_mat44(2.3);
	t_vec3f v = new_vec3f(3, 2.32, 1.2);

	v = vector_multiply(&v, &m);
	printf("%f %f %f\n", v.x, v.y, v.z);
	return (0);
}
