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
	
	printf("%d dongude, bulunan root: %lf",donguSayisi, x2);
}


double bisectionRecursive(double x0, double x1,double tol){
	double x2=(x0+x1)/2.0;
	double hata = fabs(x0-x2);
	//printf("%lf, %lf, %lf, %lf", x0, x1,tol,hata);
	
	if(hata<=tol)
	{
		printf("Recursive fonksiyonda bulunan root: %lf", x2);
		return x2;
	}
	
	if(f(x0)*f(x2)<0)
		return bisectionRecursive(x0,x2,tol);
	else
		return bisectionRecursive(x2,x1,tol);
}







int main(int argc, char *argv[]) {
	//bisectionfor(10);
	
	bisectionRecursive(0,1,0.1);
	
	return 0;
}
