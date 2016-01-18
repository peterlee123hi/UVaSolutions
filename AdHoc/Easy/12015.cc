#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())

int main() {
	int T,CN=1; scanf("%d",&T);
	while(T--) {
		vector<string> w;
		vector<int> r;
		int best=1;
		REP(i,0,10) {
			char ta[105]; int b; scanf(" %s %d",ta,&b);
			string a=ta;
			w.PB(a); r.PB(b); best=b;
		}
		vector<string> sol;
		REP(i,0,10) {
			if(r[i]==best)
				sol.PB(w[i]);
			else if(r[i]>best) {
				sol.clear();
				sol.PB(w[i]);
				best=r[i];
			} 
		}
		printf("Case #%d:\n",CN++);
		REP(i,0,SZ(sol)) printf("%s\n",sol[i].c_str());
	}
}
