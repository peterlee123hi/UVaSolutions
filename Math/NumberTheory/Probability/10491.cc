#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int NCOWS,NCARS,NSHOWS;
	while(scanf("%d %d %d",&NCOWS,&NCARS,&NSHOWS)!=EOF) {
		double pickCow=(double)NCOWS/(NCOWS+NCARS);
		double cowToCar=(double)NCARS/(NCOWS+NCARS-NSHOWS-1);
		double case1=pickCow*cowToCar;

		double pickCar=(double)NCARS/(NCOWS+NCARS);
		double carToCar=(double)(NCARS-1)/(NCOWS+NCARS-NSHOWS-1);
		double case2=pickCar*carToCar;

		printf("%0.5f\n",case1+case2);
	} exit(0);
}
