#include <stdio.h>

// function prototype
void matrix_multiply(int rows1, int cols1, int rows2, int cols2, int matrix1[][cols1], int matrix2[][cols2], int result[][cols2]);

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];

    printf("Enter the elements of the first matrix:\n");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("The number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");
        return 0;
    }

    int matrix2[rows2][cols2];

    printf("Enter the elements of the second matrix:\n");

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int result[rows1][cols2];

    // function call
    matrix_multiply(rows1, cols1, rows2, cols2, matrix1, matrix2, result);

    printf("Resultant matrix:\n");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// function definition
void matrix_multiply(int rows1, int cols1, int rows2, int cols2, int matrix1[][cols1], int matrix2[][cols2], int result[][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
