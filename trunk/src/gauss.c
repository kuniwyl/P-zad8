#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
double mod(double x)
{
	if(x < 0)return (-1)*x;
	else return x;
}

int eliminate(Matrix *mat, Matrix *b){
        int r = mat->r;
        int c = mat->c;
	int i;
	int j;
	int k;
	for( i=0; i<r-1; i++)
	{
	for( j=i+1; j<r; j++)
	{
	 double max= mod(mat->data[i][i]);        
	 int y=i+1;              
	 int ya=i;  
	 for(; y<r;y++)
	 {  
		 if(mod(mat->data[y][i]) > max)
		 {         
			 ya = y;   
			 max = mod(mat->data[y][i]);   
		 }     
	 }
	 k=0; 
		   for(; k < c; k++)
		   {        
			   double tym;   
			   tym = mat->data[i][k]; 
			   mat->data[i][k] = mat->data[ya][k];  
			   mat->data[ya][k] = tym; 
		   }   
		   double z = b->data[i][0];
		   b->data[i][0] = b->data[ya][0]; 
		   b->data[ya][0] = z;        
		if(mat->data[i][i] == 0)return 1;
		double tym = (-1) * mat->data[j][i] / mat->data[i][i];	
		for( k=i; k<r; k++)
		{
			mat-> data[j][k] += tym * mat->data[i][k]; 
		}
		b->data[j][0] += tym * b->data[i][0];
	}
}
	return 0;
}

