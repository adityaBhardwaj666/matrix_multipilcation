#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
	int r,c,i,j;
	
	r=atoi(argv[1]);   //converting the command line args
	c=atoi(argv[2]);
	
	
	if(r<0||c<0)
	 {
	   printf("Enter positive values only");
	   return 1;
	 }
	 
	 int mat[r][c];         //declaring the matrix
	 
	 for(i=0;i<r;i++){      
	  for(j=0;j<c;j++){
	      mat[i][j]=rand();  //generating random numbers & save  
	   }
	  } 
	  
	 for(i=0;i<r;i++){      
	  for(j=0;j<c;j++){
	      printf("\n %d %d \t%d",i,j,mat[i][j]);  //print
	   }
	  }
	printf("\n");
   return 0;	
 }	

