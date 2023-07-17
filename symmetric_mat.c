//a square matrix is symmetric iff a[i][j]:a[j][i].Write a c code to say weather the generated matrix is symmetric or not
#include <stdio.h>

int main() {
  int n, i, j, symmetric = 1;
  printf("Enter the size of the square matrix: ");
  scanf("%d", &n);

  int mat[n][n];
  printf("Enter the matrix elements:\n");
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      if(mat[i][j] != mat[j][i]) {
        symmetric = 0;
        break;
      }
    }
    if(!symmetric) {
      break;
    }
  }

  if(symmetric) {
    printf("The matrix is symmetric.\n");
  } else {
    printf("The matrix is not symmetric.\n");
  }

  return 0;
}
