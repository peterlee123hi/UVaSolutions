#include <cstdio>
#include <map>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int TC;
	scanf("%d\n",&TC);
	while(TC--) {
		ll n,k,p;
		map<char, int > m;
		double total=0;
		char c;
		scanf("%lld\n",&n);
		REP(i,0,n) {
			c=getchar();
			scanf("%lld\n",&p);
			m[c]=p;
		}
		scanf("%lld\n",&k);
		
		REP(i,0,k) {
			string line;
			getline(cin,line);
			REP(j,0,line.length())
				if(m.find(line[j])!=m.end())
					total+=m[line[j]];
		}

		total/=100;
		printf("%0.2lf$\n",total);
		m.clear();
	}
	return 0;
}
