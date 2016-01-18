#include <cstdio>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;
double EPS = 1e-7;

double f(double x) {
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double df(double x) {
	return -p*exp(-x)+q*cos(x)-r*sin(x)+s/(cos(x)*cos(x))+2*t*x;;
}

double newton() {
	if(f(0) == 0) return 0;
	double x=0.5, x1=0.5;
	do {
		x=x1;
		x1=x-f(x)/df(x);
	} while(abs(x1-x)>EPS);
	return x1;
}

int main() {
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF) {
		if(f(0)*f(1)>0) printf("No solution\n");
		else printf("%.4f\n", newton());
	}
	return 0;
}
