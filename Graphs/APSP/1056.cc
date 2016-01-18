#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000
#define PB push_back

vector<string> id;
int AdjMat[100][100];
int p,r;
bool disconnected;

int lookup(string name) {
	REP(i,0,SZ(id)) if(name==id[i]) return i;
	return -1;
}

void addID(string name) {
	int i=lookup(name);
	if(i==-1) id.PB(name);
}

void reset() {
	id.clear();
	REP(i,0,p) REP(j,0,p)
		AdjMat[i][j]=(i==j)?0:INF;
	disconnected=false;
}

int warshall() {
	REP(k,0,p) REP(i,0,p) REP(j,0,p)
		AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
	int ans=0;
	REP(i,0,p) REP(j,0,p) {
		if(AdjMat[i][j]==INF) {
			disconnected=true;
			break;
		} ans=max(ans,AdjMat[i][j]);
	} return ans;
}

int main() {
	int C = 1;
	while(scanf("%d %d",&p,&r),p||r) {
		reset();
		REP(i,0,r) {
			string a,b; cin >> a >> b;
			addID(a); addID(b);
			int id_a=lookup(a),id_b=lookup(b);
			AdjMat[id_a][id_b]=AdjMat[id_b][id_a]=1;
		}

		int ans=warshall();
		if(disconnected) printf("Network %d: DISCONNECTED\n\n",C++);
		else printf("Network %d: %d\n\n",C++,ans);

		/* // DEBUG
		REP(i,0,SZ(id)) printf("%d:%s   ",i,id[i].c_str()); printf("\n");
		REP(i,0,p) { REP(j,0,p) printf("%10d ",AdjMat[i][j]); printf("\n"); }
		*/ 
	}
	exit(0);
}
