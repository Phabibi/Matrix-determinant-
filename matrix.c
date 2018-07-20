
/*
- Description: Matrix Determenant
- Author: Parsa Habibi
- Date : July 17th 2018
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include<time.h>


int n;

int** matrix;
int deter;

void random_matrix ()
{
  scanf("%d", &n);
  printf(" got n = %d\n", n );

  matrix = (int **)malloc(n * sizeof(int *));
  srand(time(0));
  for (int i=0; i<n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
  printf("[");

  for(int i = 0 ; i < n ; i++)
  {
    printf("\n");

    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = rand()%10;
      printf("%d ", matrix[i][j]);
    }
  }

  printf("] \n");

  return;

}


int** sub_matrix(int** mat, int len, int th_id)
{
  int k;


  int** temp_matrix = (int **)malloc(len * sizeof(int *));
  for (int i=0; i < len; i++)
  {
    temp_matrix[i] = (int *)malloc(len * sizeof(int));
  }

  /* finding the sub matricies by comparing each by using the thread id as the offset */

  for(int i = 1 ; i <= len; i++)
  {
    k = 0;
    for(int j = 0 ; j <= len ; j++)
    {
      if(j != th_id )
      {
        temp_matrix[i-1][k] = mat[i][j];
        k++;
      }
    }
  }

return temp_matrix;
}


int Determenant(int** mat , int len)
{
  int deters = 0;

  int** sub;


  if(len == 2)
  {
    deters += (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);


  }

  for(int i = 0 ; i < len ; i++)
  {
    sub = sub_matrix(mat, len-1 , i);

    if((i % 2) == 0)
      {
        deters += mat[0][i] * Determenant(sub, len-1);
      }

    else
    {
        deters += mat[0][i] * -1 * Determenant(sub, len-1);
    }

  }
   return deters;
}


void *prompt(void* arg)
{
  /* initilizing the id , and the temporary matrix  to be used */

  int id = *((int *) arg);
  int deter;

  int** temp_mat =  sub_matrix(matrix, n-1 , id);

  deter = Determenant(temp_mat , n-1);


}

void main ()
{
  random_matrix();

  pthread_t thread_id[n];

  for(int i = 0; i < n ; i++)
{
  int *arg = malloc(sizeof(*arg));
  if ( arg == NULL ) {
      fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
      exit(EXIT_FAILURE);
  }
  *arg = i;
  pthread_create(&thread_id[i],NULL,prompt,arg);
}

for(int i = 0 ; i < n ; i++)
  {
    pthread_join(thread_id[i], NULL);
  }

  printf(" the deter : %d\n", deter );

  for(int i = 0 ; i < n ; i++)
  {
    free(matrix[i]);
  }
  free(matrix);

  return;
}
