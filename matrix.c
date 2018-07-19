
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
int n;
void random_matrix ()
{
  scanf("%d", &n);
  printf(" got n = %d\n", n );
  int matrix[n][n];
  printf("[");

  for(int i = 0 ; i < n ; i++)
  {
    printf("\n");

    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = (rand()% (10 + 10) - 10) ;
      printf("%d ", matrix[i][j]);
    }
  }

  printf("] \n");

  return;

}

int Determenant(int *arr)
{
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0; j < i ; j++)
      {
        arr[i][j] *= arr
      }

    }
}

void *prompt(void* arg)
{
  int id = *((int *) arg);
  printf("the thread id %d\n", id );
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


  return;
}
