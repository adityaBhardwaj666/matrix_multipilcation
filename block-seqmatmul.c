#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
#include "time.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char*  argv[])
{
       int BLOCK_MIN,BLOCK_MAX,MATRIX_SIZE;
       int k, j, i, jj, kk;
       
       MATRIX_SIZE=atoi(argv[1]);
       BLOCK_MIN=atoi(argv[2]);
       BLOCK_MAX=atoi(argv[3]);
       
       
       int *A[MATRIX_SIZE], *B[MATRIX_SIZE], *C[MATRIX_SIZE];
                                                                      //dynamic allocation of memory
         for (i=0; i<MATRIX_SIZE; i++) {
           A[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));         
	    B[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
	     C[i] = (int *)malloc(MATRIX_SIZE * sizeof(int));
	 }
        
	
       
       
                                                // Initalize array A and B with '1's
	for (int i = 0; i < MATRIX_SIZE; ++i)
		for (int k = 0; k < MATRIX_SIZE; ++k)
			A[i][k] = B[i][k] = 0;
	
	
	   for (int i = 0; i < MATRIX_SIZE; ++i)
		for (int k = 0; k < MATRIX_SIZE; ++k)
			A[i][k] = B[i][k] = rand()%437;
	                               // Initalize our matix looping variables once
	

	
		// Iterate through the block sizes
		for (int block_size = BLOCK_MIN; block_size <= BLOCK_MAX; block_size *= 2)
		{
		

                        clock_t start=clock();
                        
			// Do block matrix multiplication
			for (k = 0; k < MATRIX_SIZE; k += block_size)
				for (j = 0; j < MATRIX_SIZE; j += block_size)
					for (i = 0; i < MATRIX_SIZE; ++i)
						for (jj = j; jj < min(j + block_size, MATRIX_SIZE); ++jj)
							for (kk = k; kk < min(k + block_size, MATRIX_SIZE); ++kk)
							     {	
								C[i][jj] += A[i][kk] * B[kk][jj];
								//printf("\n %d %d \t %d",i,jj,C[i][jj]);
                                                              }
		
                        clock_t end=clock();
			
			// Calculate the time it took to do the above task
			float exec= (end - start);

			printf("\n\n*****CONTENTS OF ANS_MATRIX*****\n");
			 for (int i = 0; i < MATRIX_SIZE; ++i)
	                      	for (int k = 0; k < MATRIX_SIZE; ++k)
		                     printf("%d %d \t %d\n",i,k,C[i][k]);
                                                             
	             
	             printf(" \nEXEC TIME %f\n", exec/CLOCKS_PER_SEC);
		
		}

	

	return 0;
}
