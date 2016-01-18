#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000

/*
 * CUSTOM DATA STRUCTURE DEFINITIONS
 */
struct state {
	int x,y,p;
	state(int x,int y,int p) { this->x=x; this->y=y; this->p=p; } };
bool operator<(const state& a,const state& b) { return a.p>b.p; }

/*
 * SSSP VARIABLES
 */
int m,n;
int grid[1000][1000];
int dist[1000][1000];
priority_queue<state> q;

/*
 * IMPLICIT GRAPH VARIABLES
 */
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

/*
 * GLOBAL VARIABLE RESETS
 */
void reset() {
	scanf("%d %d",&m,&n);
	REP(i,0,m) REP(j,0,n) dist[i][j]=INF;
	while(!q.empty()) q.pop();
}

/*
 * STATE AND COORDINATE VALIDITY
 */
bool inbounds(int x,int y) { return 0<=x&&x<m&&0<=y&&y<n; }
bool valid(state u) { return u.p<dist[u.x][u.y]; }

/*
 * SSSP VALID STATE
 */
void process(state u) {
	dist[u.x][u.y]=u.p; // RELAX DISTANCE
	q.push(u); // QUEUE FOR PROCESSING
}

int sssp() {
	dist[0][0]=grid[0][0];
	q.push(state(0,0,grid[0][0])); // INITIAL STATE

	while(!q.empty()) {
		state u=q.top(); q.pop();
		if(u.p>dist[u.x][u.y]) continue; // SKIP IF ON LONGER PATH
		REP(i,0,4) {
			int v_x=u.x+dr[i],v_y=u.y+dc[i];
			if(!inbounds(v_x,v_y)) continue; // CHECK IF INBOUNDS

			state v=state(v_x,v_y,u.p+grid[v_x][v_y]); // CREATE STATE
			if(valid(v)) // IF ON SHORTER PATH
				process(v); // PROCESS SHORTER PATH
		}
	} return dist[m-1][n-1];
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		reset();
		REP(i,0,m) REP(j,0,n) scanf("%d",&grid[i][j]);
		printf("%d\n",sssp());
	}
	exit(0);
}
