#include<stdlib.h>
#include<stdio.h>
void matrice_nulle(int **a , int  n )
{
	

	for(int i = 0 ; i< n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			a[i][j] = 0 ;
		}
	} 

}
void affiche(int **a , int n )
{

	for(int i = 0 ; i< n; i++)
	{
		for(int j = 0  ; j< n; j++)
		{
			printf("%d ||",a[i][j]);
		}
		
		printf("\n");
		for(int k=0;k< n;k++)
		{
			printf("+++++");
		}
		printf("\n");
	}
}
void free_(int **a, int n  )
{
	for(int i =  0 ; i < n ;i++)
	{
		free(a[i]);
	}
	free(a);
}

void samoise(int **ar , int n  )
{ 
	int i = 0 ; 
	int  j = 0 ; 
	int counter = 2 ;
	i =  0 ; 
	j = n / 2;
	int k = n*n; 
	ar[i][j]  = 1;
	while(counter <= k)
	{
		i--;
		j++;
		if(i < 0 && (j >= 0 && j < n))
		{
			i = n -1 ;
		}else if(j >= n && (i >= 0 && i < n))
		{
			j = 0 ;
		}else if((i < 0 && j >= n) || ar[i][j])
		{
			i+=2;
			j--;
		}
		ar[i][j] = counter ; 
		counter++ ; 	
	}

}
int main(void)
{
	int **a ;
	int n ; 
	printf("please enter the odd number :\n");
	do{
		scanf("%d", &n);
	}while(n % 2 == 0);

	a = (int **)malloc(sizeof(int*)*n);
	for(int i = 0 ; i< n ; i ++)
	{
		a[i] = malloc(sizeof(int )*n);
	}


	matrice_nulle(a,n);
	affiche(a,n);
	printf("\n\n\n\n");
	samoise(a ,n);
	affiche(a,n);
	free_(a,n);
	return 0;
}
