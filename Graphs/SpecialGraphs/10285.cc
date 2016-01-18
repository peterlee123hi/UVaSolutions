#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end();
#define SZ(x) ((int)(x).size())

int grid[100][100],r,c;
string name;

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

bool inbounds(int x,int y) { return 0<=x&&x<r&&0<=y&&y<c; }

int backtrackH(int i,int j) {
	int ans=0;
	REP(d,0,4) {
		int ni=i+dr[d],nj=j+dc[d];
		if(inbounds(ni,nj)&&grid[i][j]>grid[ni][nj])
			ans=max(ans,backtrackH(ni,nj));
	}
	return 1+ans;
}

int backtrack() {
	int ans=0;
	REP(i,0,r) REP(j,0,c) ans=max(ans,backtrackH(i,j));
	return ans;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		cin >> name; scanf("%d %d",&r,&c);
		REP(i,0,r) REP(j,0,c) scanf("%d",&grid[i][j]);
		printf("%s: %d\n",name.c_str(),backtrack());
	}
	exit(0);
}
