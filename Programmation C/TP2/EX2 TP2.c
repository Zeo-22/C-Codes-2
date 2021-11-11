#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float Dichotomie(float(*f)(float), float a, float b, int n){
	float alphan;
	int i;
	for(i=0;i<n;i++){
		alphan = (a+b)/2;
		if(f(alphan)>=0)
			b = alphan;
		if(f(alphan)<0)
			a = alphan;
	}
	return(alphan);
}


float fonction(float x){
	return(pow(x,2)-2);
}


int main(){
	float(*f)(float) = &fonction;
	int a = 1;
	int b = 3;
	int n = 10;
	float alphan = Dichotomie(f,a,b,n);
	printf("%f",alphan);
	return 0;
}
