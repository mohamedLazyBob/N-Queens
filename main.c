#include "ft_nQueen.h"

int	main(int argc, char **argv)
{
	int i = 0;
	int j;
	int	**tab;
	int N;
	if (argc != 2)
		return (1);
	N = atoi(argv[1]);
	tab = (int**)malloc(N * sizeof(int*));
	while (i < N)
	{
		tab[i] = (int*)malloc(N * sizeof(int));
		i++;
	}
	i = 0;
	while(i < N)
	{
		j = 0;
		while(j < N)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}

	ft_solve(tab, 0, N);
	return (0);
}
