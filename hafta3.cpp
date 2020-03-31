#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


double fonk(double x){
	return pow((6+x),0.33333333333);
}

void soru3(){
	double x0=0.00000;
	double x1=0.00000;
	double e=0.001;
	double hata=0.0000;
	
	do {
		x1=fonk(x0);
		printf("%lf \n", x1);
		hata=fabs(x1-x0);	
		printf("%lf", x1);
		x0=x1;
	}while(hata>e);
	
	//printf("%lf",fonk(x0));

}

int main(int argc, char *argv[]) {
	soru3();
	return 0;
}
