#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define sz(x) ((int)(x).size())

int main() {
	int CN=1;
	vector<string> t;
	string s;
	bool decode=true;
	while(cin>>s) {
		if(s=="9") {
			printf("Set %d is%s immediately decodable\n",CN++,(decode)?"":" not");
			t.clear();
			decode=true;
		}
		if(!decode) continue;
		rep(i,0,sz(t))
			if(t[i].find(s)==0||s.find(t[i])==0) decode=false;
		t.pb(s);
	}
}
