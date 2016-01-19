#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

struct fraction {
	int num,den;
};

fraction table[10000010];

void loadTable() {
	int r=0,c=0;
	REP(i,0,10000010) {
		table[i].num=r+1;
		table[i].den=c+1;
		if(r==0&&c%2==0) { //left
			c++;
		} else if(c==0&&r%2==1) { //right
			r++;
		} else {
			if((r+c)%2==0) { //up left
				r--; c++;
			} else { //down right
				r++; c--;
			}
		}
	}
}

int main() {
	loadTable();
	int n;
	while(scanf("%d",&n)!=EOF)
		printf("TERM %d IS %d/%d\n",n,table[n-1].num,table[n-1].den);
}
