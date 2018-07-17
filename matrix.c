#include <stdlib.h>
#include <stdio.h>



void random_matrix ()
{
  int n;
  scanf("%d", &n);
  printf(" got n = %d\n", n );
  int matrix[n][n];

  for(int i = 0 ; i < n ; i++)
  {
    printf("\n");

    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = (rand()% (100 - 2 + 1) + 2) ;
      printf("%d ", matrix[i][j]);
    }
  }
  printf("\n");

  return;

}

void main ()
{
  random_matrix();
  return;
}
