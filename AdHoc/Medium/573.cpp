#include <cstdio>
using namespace std;

int main() {
	double h,u,d,f;
	while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f),h) {
		double height = 0, speed = u;
		double dMin = u*f/100;
		int day = 0;
		while(0<=height) {
			day++;
			if(speed<0) speed = 0;
			height += speed;
			if(h<height) break;
			height -= d;
			speed -= dMin;
		}
		if(h<height)
			printf("success on day %d\n",day);
		else
			printf("failure on day %d\n",day);
	}
	return 0;
}
