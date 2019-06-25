#ifndef FT_NQUEEN_H
#define FT_NQUEEN_H

#include <stdio.h>
#include <stdlib.h>

void	ft_print(int **tab, int N);
int		ft_solve(int **tab, int col, int N);
int		ft_safe(int	**tab, int col, int row, int N);

#endif
