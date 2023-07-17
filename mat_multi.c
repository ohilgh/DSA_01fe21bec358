//c code to multiply two matrices use user defined functions to perform multiplication
//using pointer as argument
#include<stdio.h>
int main() {
    int a[10][10], b[10][10], c[10][10], n, i, j, k;

    printf("Enter the value of N: ");
    scanf("%d", & n);
    printf("Enter the elements of A: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", & a[i][j]);
        }
         }

    printf("Enter the elements of B: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", & b[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("The product is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", c[i][j]);
        }
    }
}
