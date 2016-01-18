#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()

int main() {
	string str;
	while(getline(cin,str),str!="#") {
		string next(str);
		next_permutation(ALL(next));
		if(str>=next)
			printf("No Successor\n");
		else
			printf("%s\n",next.c_str());
	}
	return 0;
}
