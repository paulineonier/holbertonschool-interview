#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Affiche une grille 3x3
 * @grid: Grille 3x3 à afficher
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Vérifie si une grille est stable (toutes les cases <= 3)
 * @grid: Grille 3x3 à vérifier
 *
 * Return: 1 si stable, 0 sinon
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Effectue une étape d'éboulement sur la grille
 * @grid: Grille 3x3 à stabiliser
 */
static void topple(int grid[3][3])
{
	int next_grid[3][3] = {0};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				next_grid[i][j] -= 4;
				if (i > 0)
					next_grid[i - 1][j] += 1;
				if (i < 2)
					next_grid[i + 1][j] += 1;
				if (j > 0)
					next_grid[i][j - 1] += 1;
				if (j < 2)
					next_grid[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] += next_grid[i][j];
	}
}

/**
 * sandpiles_sum - Calcule la somme de deux tas de sable 3x3
 * @grid1: Première grille (résultat final stocké ici)
 * @grid2: Seconde grille
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
