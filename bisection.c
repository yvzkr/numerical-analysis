#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x0){
	return pow(2,x0 ) - 5 * x0 + 2;
}

double bisectionRecursiveReferans(double x0, double x1, int k){
	double x2;
	int i=1;
	x2=(x0+x1)/2.0;
	if(k==10)
	{
		printf("Bisection: Recursive %d dongude, bulunan root: %lf \n",k, x2);
		return x2;
	}
	if(f(x0)*f(x2)<0)
		bisectionRecursiveReferans(x0,x2,k+1);
	else
		bisectionRecursiveReferans(x2,x1,k+1);
}

double bisectionRecursive(double x0, double x1,double tol){
	double x2=(x0+x1)/2.0;
	double hata = fabs(x0-x2);
	//printf("%lf, %lf, %lf, %lf", x0, x1,tol,hata);
	
	if(hata<=tol)
	{
		printf("Bisection: Recursive fonksiyonda hata:%lf bulunan root: %lf \n",hata, x2);
		return x2;
	}
	
	if(f(x0)*f(x2)<0)
		return bisectionRecursive(x0,x2,tol);
	else
		return bisectionRecursive(x2,x1,tol);
}

void bisectionWhile(double x0,double x1,double tol){

	double x2;
	double hata=tol+1;
	int donguSayisi=0;
	while(hata>tol){
		x2=(x0+x1)/2.0;
		hata = fabs(x1-x2);
		if(f(x0)*f(x2)<0)
			x1=x2;
		else
			x0=x2;
		donguSayisi++;
	}
	
	printf("Bisection: For ile %d dongude,bulunan hata:%lf bulunan root: %lf \n",donguSayisi,hata, x2);
}


int main(int argc, char *argv[]) {
	
	double x0=0;
	double x1=1;
	double x2;
	

	int i=1;
	
	for(i=1; i<10; ++i){
		x2=(x0+x1)/2.0;
		if(f(x0)*f(x2)<0)
			x1=x2;
		else
			x0=x2;
	}
	
	printf("Root: %lf ", x2);
	
	
	
	
	
	
	/*bisectionRecursive(0,1,0.1);
	
	bisectionRecursiveReferans(0,1,10);
	
	bisectionWhile(0,1,0.1);*/
	
		
	return 0;
}
