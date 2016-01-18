#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define SZ(x) ((int)(x).size())

int TC;
vector<string> vs;
string line;

string rm_white(string s) {
	int i=0;
	while(i<s.length()) {
		if(s[i]==' ') s.erase(i,1);
		else i++;
	}
	return s;
}

bool is_anagram(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return rm_white(s1) == rm_white(s2);
}

int main() {
	scanf("%d\n\n",&TC);
	while(TC--) {
		while(getline(cin,line),line!="")
			vs.PB(line);
		sort(vs.begin(),vs.end());
		REP(i,0,SZ(vs)-1)
			REP(j,i+1,SZ(vs))
			if(is_anagram(vs[i],vs[j]))
				printf("%s = %s\n",vs[i].c_str(),vs[j].c_str());
		vs.clear();
		if(TC) printf("\n");
	}
}
