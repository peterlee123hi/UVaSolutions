#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second
#define INF 1000000000
#define SET(x,s) memset(x,s,sizeof x)

const int UNVISITED=-1;

int n,m,dfs_counter;
vector<string> names;
vi dfs_num,dfs_low;
vector<vii> AdjList;
stack<int> trace;
stack<string> ans;

int lookupName(string name) {
	REP(i,0,n) if(names[i]==name) return i;
	return -1;
}

void reset(int n) {
	names.assign(n,"");
	dfs_counter=0;
	dfs_num.assign(n,UNVISITED);
	dfs_low.assign(n,0);
	AdjList.assign(n,vii(0));
}

void tarjanSCC(int i) {
	dfs_num[i]=dfs_low[i]=dfs_counter++;
	trace.push(i);
	REP(j,0,SZ(AdjList[i])) {
		ii v=AdjList[i][j];
		if(dfs_num[v.FI]==UNVISITED)
			tarjanSCC(v.FI);
		if(dfs_num[v.FI]!=UNVISITED)
			dfs_low[i]=min(dfs_low[i],dfs_low[v.FI]);
	}

	if(dfs_num[i]==dfs_low[i]) {
		int v=trace.top(); trace.pop(); dfs_num[i]=UNVISITED;
		string circle="";
		while(i!=v) {
			//printf("%s, ",names[v].c_str());
			circle=", "+names[v]+circle;
			v=trace.top(); trace.pop();
		}
		//printf("%s\n",names[v].c_str());
		circle=names[v]+circle;
		ans.push(circle);
	}
}

int main() {
	int CN=1;
	while(scanf("%d %d",&n,&m),n||m) {
		reset(n);
		if(CN>1) printf("\n");
		printf("Calling circles for data set %d:\n",CN++);

		int id=0;
		REP(i,0,m) {
			string a,b;
			cin >> a >> b;
			int id_a=lookupName(a),id_b=lookupName(b);
			if(id_a==-1) {
				id_a=id++;
				names[id_a]=a;
			}
			if(id_b==-1) {
				id_b=id++;
				names[id_b]=b;
			}
			AdjList[id_a].PB(MP(id_b,0));
		}

		REP(i,0,n)
			if(dfs_num[i]==UNVISITED) {
				dfs_counter=0;
				tarjanSCC(i);
			}

		/*DEBUG
		REP(i,0,n) {
			printf("%d:",i);
			REP(j,0,SZ(AdjList[i]))
				printf(" %d",AdjList[i][j].FI);
			printf("\n");
		}
		printf("DFS_NUM:");
		REP(i,0,n) printf(" %d",dfs_num[i]); printf("\n");
		printf("DFS_LOW:");
		REP(i,0,n) printf(" %d",dfs_low[i]); printf("\n");*/
		while(!ans.empty()) {
			printf("%s\n",ans.top().c_str()); ans.pop();
		}
	}
}
