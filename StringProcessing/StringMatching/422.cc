#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int,int> ii;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define sz(x) ((int)(x).size())
#define fi first
#define se second

int n;
char mat[110][110];
string w;
ii s,e;

void reset() {
	cin>>w;
	s=ii(-1,-1);
	e=ii(-1,-1);
}

bool search(int i,int r, int c) {

}

void solve() {

}

int main() {
	scanf("%d",n);
	rep(r,0,n) rep(c,0,n) scanf(" %c",mat[r][c]);
	w="1";
	while(w!="0") {
		solve();
		if(s.fi==-1) printf("Not found\n");
		else printf("%d,%d %d,%d\n",s.fi,s.se,e.fi,e.se);
	}
}
