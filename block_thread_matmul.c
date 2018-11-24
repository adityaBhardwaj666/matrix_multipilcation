#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "time.h"
#include"pthread.h"
#include<mpi.h>


#define MAX 30
#define MAX_THREAD 10
#define MATRIX_SIZE 2000
#define DENOM 3
int step_i=0;


 int *A[MATRIX_SIZE], *B[MATRIX_SIZE], *C[MATRIX_SIZE];             //row pointers to matrix
                                                                      
int BLOCK_MIN,BLOCK_MAX;
      

// ####################################################

int min(int a, int b)
{
	return a < b ? a : b;
}

void* multi(void* arg)
{
    int core = step_i++;
    	int k, j, i, jj, kk;
 
    // Each thread computes 1/DENOM th of matrix multiplication
    for (int i = core * MAX / DENOM; i < (core + 1) * DENOM / DENOM; i++) 
       {
          for (int block_size = BLOCK_MIN; block_size <= BLOCK_MAX; block_size *= 2)
	    {
	    
                        
          // Do block matrix multiplication
		for (k = 0; k < MATRIX_SIZE; k += block_size)
		 for (j = 0; j < MATRIX_SIZE; j += block_size)
		  for (i = 0; i < MATRIX_SIZE; ++i)
		   for (jj = j; jj < min(j + block_size, MATRIX_SIZE); ++jj)
		    for (kk = k; kk < min(k + block_size, MATRIX_SIZE); ++kk)
		  C[i][jj] += A[i][kk] * B[kk][jj];
                                                              
              } 
        }
}

//######################################################################

int main(int argc, char*  argv[])
{
       
       
      // MATRIX_SIZE=atoi(argv[1]);
       BLOCK_MIN=atoi(argv[1]);
       BLOCK_MAX=atoi(argv[2]);
       
      for (int i=0; i<MATRIX_SIZE; i++) {                            //dynamic allocation of memory
           A[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));         
	    B[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
	     C[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
          }
         
                  
                                                                // Initalize array A and B with 'random values' 
	for (int i = 0; i < MATRIX_SIZE; ++i)
		for (int k = 0; k < MATRIX_SIZE; ++k)
			A[i][k] = B[i][k] = 0;
	
	
        for (int i = 0; i < MATRIX_SIZE; ++i)
	  for (int k = 0; k < MATRIX_SIZE; ++k){
		A[i][k] = rand()%437;
		B[i][k]= rand()%312;
	                                                       // Initalize our matix looping variables once
             }
	
	 
	  pthread_t threads[MAX_THREAD];                         // creating threads
	  clock_t start=clock();                                 // start time
	  
	 for (int i = 0; i < MAX_THREAD; i++) {
             int* p;
             pthread_create(&threads[i], NULL, multi, (void*)(p));
           }
 
                                                                         // joining and waiting for all threads to complete
         for (int i = 0; i < MAX_THREAD; i++) 
               pthread_join(threads[i], NULL);    
           
           clock_t end = clock();
	  	
	printf("\n\n*****CONTENTS OF ANS_MATRIX*****\n");         // print ANSWER MATRIX
	for (int i = 0; i < MATRIX_SIZE; ++i)
	  for (int k = 0; k < MATRIX_SIZE; ++k)
             printf(" %d %d \t %d\n",i,k,C[i][k]);
                         
        
        float exec = end -start;                                    
        printf(" \nEXEC TIME %f\n",exec/CLOCKS_PER_SEC);       //print exec time req for matrix multipy + thread(creation+joining)
		
	return 0;
}


