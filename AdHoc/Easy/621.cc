#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T; scanf("%d",&T);
	string s;
	while(T--) {
		cin>>s;
		if(s=="1" || s=="4" || s=="78") printf("+\n");
        else if(s[s.length()-1]=='5' && s[s.length()-2]=='3') printf("-\n");
        else if(s[s.length()-1]=='4' && s[0]=='9') printf("*\n");
        else if(s[0]=='1' && s[1]=='9' && s[2]=='0') printf("?\n");
	} exit(0);
}
