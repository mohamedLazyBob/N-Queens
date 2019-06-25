#include "ft_nQueen.h"

/** note : this is a non important project, soo there no optimisation and such thing like that **/

/************************************************************/
/** this function printf the 3 dementionalle table/matrice **/
/************************************************************/

void	ft_print(int	**tab, int N)
{
	static int solution_num;
	int j;
	printf("solution number == %d;\n", solution_num++);
	for(j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			printf("%d;\t", tab[j][i]);
		}
		printf("\n");
	}
}

/*************************************************************/
/** this function test if that case is valid.				**/
/** meaning that we can put a queen there and it won't		**/
/** attack any other one;									**/	
/*************************************************************/

int	ft_safe(int **tab, int col, int row, int N)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
		if (tab[i][col] == 1)
			return (0);
	for (j = 0; j < col; j++)
		if (tab[row][j] == 1)
			return (0);
	i--;
	j--;
	while (i >= 0 && j >= 0)
	{
		if (tab[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	while (row < N && col >= 0)
	{
		if (tab[row][col] == 1)
			return (0);
		row++;
		col--;
	}
	return (1);
}

/*****************************************************************/
/** this function check if there is a valid row in this colum,	**/
/** if it find one it passes to the next column recursively		**/
/*****************************************************************/

int		ft_solve(int **tab, int col, int N)
{
	if (col == N)
	{
		ft_print(tab, N);
		printf("\n--------------------\n");
		return (0);
	}
	for (int row = 0; row < N; row++)
	{
		if (ft_safe(tab, col, row, N) == 1)
		{
			tab[row][col] = 1;
			if (ft_solve(tab, col + 1, N) == 1)
				return (1);
			tab[row][col] = 0;
		}
	}
	return (0);
}
