#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

char mat[100][100];
int n,m;

int inBounds(int i, int j) {
	return 0 <= i && 0 <= j && i < n && j < m;
}

int numOfAdjMines(int i, int j) {
	int ans = 0;
	REP(x,i-1,i+2)
		REP(y,j-1,j+2)
			if(inBounds(x,y)&&!(x==i&&y==j)&&mat[x][y]=='*')
				ans++;
	return ans;
}

int main() {
	string line;
	int fieldN = 1;
	while(scanf("%d %d\n",&n,&m),n,m) {
		if(n == 0 && m == 0) break;
		if(fieldN > 1) printf("\n");

		REP(i,0,n) {
			getline(cin,line);
			REP(j,0,m) {
				mat[i][j]=line[j];
			}
		}

		printf("Field #%d:\n",fieldN++);

		REP(i,0,n) {
			REP(j,0,m)
				if(mat[i][j]=='*')
					printf("*");
				else
					printf("%d",numOfAdjMines(i,j));

			printf("\n");
		}
	}
	return 0;
}
