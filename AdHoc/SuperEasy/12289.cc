#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int diff(string a, string b) {
	if(a.length()!=b.length()) {
		int la=a.length();
		int lb=b.length();
		return abs(la-lb);
	}
	int d=0;
	REP(i,0,a.length())
		if(a[i]!=b[i]) d++;
	return d;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		string word; cin>>word;
		if(diff("one",word)<=1) printf("1\n");
		else if(diff("two",word)<=1) printf("2\n");
		else printf("3\n");
	} exit(0);
}
