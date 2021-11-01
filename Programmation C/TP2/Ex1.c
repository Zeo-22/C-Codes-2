#include<stdlib.h>
#include<stdio.h>

float **sum_m(float **A, float **B, int n){
	float **S = malloc(sizeof(float *)*n);
	int i = 0;
	while(i<n){
		S[i] = malloc(sizeof(float)*n);
		i++;
	}
	i=0;
	int j = 0;
	while(i<n){
		while(j<n){
			S[i][j] = A[i][j] + B[i][j];
			j++;
		}
		j=0;
		i++;
	}
	return(S);
}

float **mult_m(float **A, float **B, int n){
	float **P = malloc(sizeof(float *)*n);
	int i = 0;
	while(i<n){
		P[i] = malloc(sizeof(float)*n);
		i++;
	}
	i=0;
	int j = 0;
	int k = 0;
	while(i<n){
		while(j<n){
			P[i][j]=0;
			while(k<n){
				P[i][j] = P[i][j] + A[i][k] * B[k][j];
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return(P);
}


float **transpose_m(float **A,int n){
	float **T = malloc(sizeof(float *)*n);
	int i = 0;
	while(i<n){
		T[i] = malloc(sizeof(float)*n);
		i++;
	}
	i=0;
	int j = 0;
	while(i<n){
		while(j<n){
			T[i][j] = A[j][i];
			j++;
		}
		j=0;
		i++;
	}
	return(T);
}

float **dia_m(float **A, int n){
	float **D = malloc(sizeof(float *)*n);
	int i = 0;
	while(i<n){
		malloc(sizeof(float)*n);
		i++;
	}
	i=0;
	while(i<n){
		D[0][i]=A[i][i];
		D[1][i]=A[i][n-i-1];
		i++;
	}
	return(D);
}


int main(){
	int n = 2;
	float **A = malloc(sizeof(float*) * n);
	int i = 0;
	while(i<n){
		A[i]=malloc(sizeof(float)*n);
		i++;
	}
	float **B = malloc(sizeof(float *)*n);
	i = 0;
	while(i<n){
		B[i]=malloc(sizeof(float)*n);
		i++;
	}
	i = 0;
	int j = 0;
	while(i<n){
		while(j<n){
			printf("Saisir l element %d,%d de A : ",i,j);
			scanf("%f",&A[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	while(i<n){
		while(j<n){
			printf("Saisir l element %d,%d de B : ",i,j);
			scanf("%f",&B[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	float **S = sum_m(A,B,n);
	i=0;
	while(i<n){
		while(j<n){
			printf("L element %d,%d de S est : %f\n",i,j,S[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	float **P = mult_m(A,B,n);
	i=0;
	while(i<n){
		while(j<n){
			printf("L element %d,%d de P est : %f\n",i,j,P[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	float **T = transpose_m(A,n);
	i=0;
	while(i<n){
		while(j<n){
			printf("L element %d,%d de T est : %f\n",i,j,T[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	float **D = dia_m(A,n);
	i=0;
		while(i<n){
			while(j<n){
			printf("L element %d,%d de D est : %f\n",i,j,D[i][j]);
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	while(i<n){
		free(A[i]);
		free(B[i]);
		free(S[i]);
		free(P[i]);
		free(T[i]);
		free(D[i]);
		i++;
	}
	free(A);
	free(B);
	free(S);
	free(P);
	free(T);
	free(D);
	return 0;
}













