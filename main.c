#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


double f(double sayi){
	return pow(2,sayi ) - 5 * sayi + 2;
}

void bisectionfor(int donguSayisi){
	double x0=0;
	double x1=1;
	double x2;
	

	int i=1;
	
	for(i=1; i<donguSayisi; ++i){
		x2=(x0+x1)/2.0;
		if(f(x0)*f(x2)<0)
			x1=x2;
		else
			x0=x2;
	}
	
	printf("Bisection: For ile %d dongude, bulunan root: %lf \n",donguSayisi, x2);
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


double f1(double x){
	return ((x* cos(x) + pow(x,2)- sin(x)+2 )/(cos(x)+2*x));
}

double newtonRapsonFor(double x0,int donguSayisi){
	int i=0;
	for(i=0; i<donguSayisi; i++){
		x0=f1(x0);
		//printf("NewtnRapson: For ile %d dongude, bulunan root: %lf \n",i+1, x1);
	}
	printf("NewtnRapson: For ile %d dongude, bulunan root: %lf \n",donguSayisi, x0);
}


double newtonRapsonRecursiveReferans(double x0,int donguSayisi, int sayac){
	
	x0=f1(x0);
	if(sayac<donguSayisi){
		return newtonRapsonRecursiveReferans(x0,donguSayisi,sayac+1);
	}else{
		printf("NewtnRapson: For ile %d dongude, bulunan root: %lf \n",donguSayisi, x0);
		return x0;
	}

}

double newtonRapsonDoWhileWithError(double x0,double tol){
	
	double x1,hata;
	do{
		x1=f1(x0);
		hata=fabs(x1-x0);
		x0=x1;
	}while(hata>tol);
	
	printf("NewtnRapson: doWhile ile %lf hata, bulunan root: %lf \n",hata, x1);
	
}



double newtonRapsonRecursive(double x0,double tol){
	
	double x1=f1(x0);
	double hata=fabs(x1-x0);
	if(hata<=tol)
	{
		printf("NewtnRapson: Recursive ile %lf hata, bulunan root: %lf \n",hata, x1);
		return x1;
	}
	else
		return newtonRapsonRecursive(x1,tol);
	

	
}





int main(int argc, char *argv[]) {
	bisectionfor(10);
	
	bisectionRecursive(0,1,0.1);
	
	bisectionRecursiveReferans(0,1,10);
	
	bisectionWhile(0,1,0.1);
	
	newtonRapsonFor(1,10);
	
	newtonRapsonRecursiveReferans(1,10,0);
	
	newtonRapsonDoWhileWithError(1,0.1);
	
	newtonRapsonRecursive(1,0.1);
	
	return 0;
}
