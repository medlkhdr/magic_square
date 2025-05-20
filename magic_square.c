#include <stdio.h>
#include <stdlib.h>

int **create_zero_matrix(int n)
{
    int **matrix = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = calloc(n, sizeof(int));
    return matrix;
}

void print_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void fill_magic_square(int **matrix, int n)
{
    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        matrix[i][j] = num++;
        int new_i = (i - 1 + n) % n;
        int new_j = (j + 1) % n;
        if (matrix[new_i][new_j])
            i = (i + 1) % n;
	else
	 {
            i = new_i;
            j = new_j;
        }
    }
}

int main()
{
    int n;

    do
    {
        printf("Enter an odd number for the magic square size: ");
        scanf("%d", &n);
    } while (n % 2 == 0);

    int **magic_square = create_zero_matrix(n);
    fill_magic_square(magic_square, n);

    printf("\nMagic Square of order %d:\n", n);
    print_matrix(magic_square, n);

    free_matrix(magic_square, n);
    return 0;
}

