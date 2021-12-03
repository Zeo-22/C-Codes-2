#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define n 3

//EX 1
float PolyLagrange(float *X,float x,int i){
	float L=1;
	int j;
	for(j=0;j<n;j++){
		if(j!=i){
			L=L*((x-X[j])/(X[i]-X[j]));
		}
	}
	return(L);
}


//EX 2
float fonction(float x){
	return(sin(x));
}


float InterpLagrange(float *X,float x,float(*f)(float)){
	float P = 0;
	int i;
	for(i=0;i<n;i++)
		P = P + f(X[i])*PolyLagrange(X,x,i);
	return P;
}


//EX 3-4
void draw(float(*f)(float),float a,float b){
	FILE *fp = NULL;
	FILE *gnupipe = NULL;
	char *GnuCommands [] = {"set title \"Demo\"", "plot 'data.tmp'"};
	fp = fopen("data.tmp","w");
	gnupipe = _popen("gnuplot -persistent","w");
	float X[n];
	int k = a;
	int j;
	for(j=0;j<n;j++){
		X[j]=k;
		k = k+((b-a)/(n-1));
	}
	/*Tchebychev Nodes :
	for(j=0;j<=n;j++){
		X[j]=(a+b)/2 +((b-a)/2)*cos(((2*j + 1) / (n+1)) * M_PI/2)*/
	float x[n*100];
	k = a;
	float y1[n*100];
	float y2[n*100];
	for(j=0;j<n*100;j++){
		x[j]=k;
		k = k+((b-a)/(n*100)-1);
		y1[j]=f(x[j]);
		y2[j]=InterpLagrange(X,x[j],f);
		fprintf(fp,"%f %f\n",x[j],y1[j]); 
		fprintf(fp,"%f %f\n",x[j],y2[j]);
	}
	for(j=0;j<2;j++)
		fprintf(gnupipe,"%s\n",GnuCommands[j]);
	/*  DRAW WITH GNUPLOT  */
}



int main(){
	float a = 0;
	float b = 2;
	float X[n];
	int k = a;
	int j;
	for(j=0;j<n;j++){
		X[j]=k;
		k = k+((b-a)/(n-1));
	}
	float x = 6;
	int i = 0;
	float L = PolyLagrange(X,x,i);
	printf("%f\n",L);
	float(*f)(float) = &fonction;
	float P = InterpLagrange(X,x,f);
	printf("%f",P);
	draw(f,a,b);
	return 0;
}
