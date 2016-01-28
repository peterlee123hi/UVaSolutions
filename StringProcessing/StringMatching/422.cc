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

int dr[]={-1,-1,0,1,1,1,0};
int dc[]={-1,1,1,1,0,-1,-1};
bool inbounds(int r,int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void reset() {
	cin>>w;
	s=ii(-1,-1);
	e=ii(-1,-1);
}

bool search(int i,int r, int c,int dir) {
	if(!inbounds(r,c)||mat[r][c]!=w[i]) return false;
	if(i==0) {
		s=ii(r,c);
		bool found=search(i+1,r+dr[dir],c+dc[dir],dir);
		if(!found) s=ii(-1,-1);
		return found;
	} else if(i==w.length()-1) {
		e=ii(r,c);
		return true;
	}
	bool found=search(i+1,r+dr[dir],c+dc[dir],dir);
	return found;
}

void solve() {
	rep(r,0,n) rep(c,0,n) rep(d,0,7) {
		if(w.length()==1) {
			if(mat[r][c]==w[0]) {
				s=e=ii(r,c);
				return;
			}
		} else {
			bool found=search(0,r,c,d);
			if(found) return;
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(r,0,n) rep(c,0,n) scanf(" %c",&mat[r][c]);
	w="1";
	while(w!="0") {
		reset();
		if(w=="0") break;
		solve();
		if(s.fi==-1) printf("Not found\n");
		else printf("%d,%d %d,%d\n",s.fi+1,s.se+1,e.fi+1,e.se+1);
	} exit(0);
}
