
#include "matrix.h"

t_matrix	g_garbage[100];
t_i32		g_cnt = 0;

void		garbage_collector(t_matrix44 m)
{
	g_garbage[g_cnt++] = m;
}

void		manual_dispose(t_matrix *m)
{
	int	i;

	i = 0;
	while (i < g_cnt)
	{
		if (g_garbage[i].id == m->id)
		{
			g_garbage[i] = g_garbage[g_cnt];
			g_cnt--;
		}
		i++;
	}
}

void		dispose_garbage()
{
	while (g_cnt > 0)
	{
		if (g_garbage[g_cnt].mat != NULL)
			kill_matrix(&g_garbage[g_cnt]);
		g_cnt--;
	}
}
