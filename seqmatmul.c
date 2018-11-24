#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc , char *argv[])
{
	int r1,r2,c1,c2,i,j,k;
	
	r1=atoi(argv[1]);   //converting the command line args
	c1=atoi(argv[2]);
	r2=atoi(argv[3]);
	c2=atoi(argv[4]);
	
	if(r1<0||c1<0||r2<0||c2<0)
	 {
	   printf("Enter positive values only");
	   return 1;
	 }
	 
	
	int *mat1[r1], *mat2[r2];
         
         for (i=0; i<r1; i++)
           mat1[i] = (int *)malloc(c1 * sizeof(int));         //dynamically alloting memory
	 
	 for (i=0; i<r2; i++)
           mat2[i] = (int *)malloc(c2 * sizeof(int));         
	 
	
	 for(i=0;i<r1;i++){      
	  for(j=0;j<c1;j++){
	      mat1[i][j]=rand()%233;  //generating random numbers & save  
	   }
	  }
	  
	 for(i=0;i<r2;i++){      
	  for(j=0;j<c2;j++){
	      mat2[i][j]=rand()%333;  //generating random numbers & save  
	   }
	  } 	 
	  
      
	
	 int *result[r1];
	 
	 for (i=0; i<r1; i++)
           result[i] = (int *)malloc(c2 * sizeof(int));         //declaring the matrix
	 
	clock_t start = clock();
	
	for(i=0;i<r1;i++){
	 for(j=0;j<c2;j++){
	    result[i][j]=0;
	    for(k=0;k<c1;k++){
	      result[i][j]+=mat1[i][k]*mat2[k][j];
	    }
	   }
	  }
        
        clock_t end = clock();
        double time_elapsed = (end - start);

        // printf("\n ## TIME ELAPSED IN MUL -> %lf\n",time_elapsed);
       printf("\n ## RESULT MATRIX AFTER MULTIPLICATION : ");

	for(i=0;i<r2;i++){      
	  for(j=0;j<c2;j++){
	      printf("\n %d %d \t%d",i,j,result[i][j]);                              //print RESULT
	   }
	  }
	printf("\n");
	
       	printf("\n ## TIME ELAPSED IN MUL -> %lf\n",time_elapsed/CLOCKS_PER_SEC);
	  
   
   return 0;	
 }	
 

