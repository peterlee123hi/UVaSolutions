#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back

vector<ll> table;
set<ll> used;

void loadTable() {
	table.PB(1); table.PB(2); table.PB(3); table.PB(5); table.PB(7);
	used.insert(1); used.insert(2); used.insert(3); used.insert(5); used.insert(7);
	int i=0;
	while(SZ(table)<20000) {
		REP(j,0,i+1) {
			ll num=table[i]*table[j];
			if(used.find(num)==used.end()) {
				table.PB(num);
				used.insert(num);
			}
		} i++;
	}
	sort(ALL(table));
}

int main() {
	loadTable();
	int n;
	while(scanf("%d",&n),n) {
		string suffix="th";
		if(n%10==1&&(n%100)/10!=1) suffix="st";
		else if(n%10==2&&(n%100)/10!=1) suffix="nd";
		else if(n%10==3&&(n%100)/10!=1) suffix="rd";
		printf("The %d%s humble number is %lld.\n",n,suffix.c_str(),table[n-1]);
	}
}
