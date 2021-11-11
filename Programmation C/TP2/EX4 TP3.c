#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float fonction(float x){
	return(pow(x,2)-2);
}

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

float Dichotomie2(float(*f)(float), float a, float b, float e){
	float D = Dichotomie(f,a,b,floor(log2((b-a)/e))+1);
	return(D);
}

int main(){
	float(*f)(float)=&fonction;
	float a = 1;
	float b = 3;
	float e = 0.0001;
	float D = Dichotomie2(f,a,b,e);
	printf("%f",D);
	return 0;
}





