#include<stdlib.h>
#include<stdio.h>
#include<math.h>


float fonction(float x){
	return(pow(x,2)-2);
}


float derivee(float x){
	return(2*x);
}


float newton(float(*f)(float),float(*g)(float),float a,int n){
	float alphan = a - (f(a)/g(a));
	int i;
	for(i=0;i<n;i++)
		alphan = alphan - (f(alphan)/g(alphan));
	return(alphan);
}


int main(){
	float(*f)(float) = &fonction;
	float(*g)(float) = &derivee;
	float a = 1;
	int n = 10;
	float N = newton(f,g,a,n);
	printf("%f",N);
	return 0;
}
