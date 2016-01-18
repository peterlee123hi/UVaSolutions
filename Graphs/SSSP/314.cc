#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000

/* (STATE-SPACE GRAPH)
 * REPRESENT STATES WITH STRUCT
 * NOTE: CAN STORE PREDECESSOR STATE AND DISTANCE
 */
struct state {
	int x,y,dir,commands;
	state(int r,int c,int dr,int com) {
		x=r; y=c; dir=dr; commands=com;
	}
};

void printState(state s) {
	printf("x=%d\ty=%d\tdirection=%d\tcommands=%d\n",s.x,s.y,s.dir,s.commands);
}

/* (IMPLICIT GRAPHS)
 * FOR IMPLICIT GRAPHS, USE THESE DATA TO NAVIGATE AND "TURN".
 * DIRECTION: NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
 * TURN RIGHT = (INDEX+1)%4
 * TURN LEFT = (INDEX+3)%4
 * MOVE FORWARD: X += DISTANCE*dr[INDEX]
 *               Y += DISTANCE*dc[INDEX]
 */ 
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
map<string, int> dir;

/* (SSSP ON UNWEIGHTED/IMPLICIT GRAPH)
 * FOR SINGLE-SOURCE SHORTEST PATH ON UNWEIGHTED GRAPH,
 * DO NOT REVISIT STATES
 */
int m,n;
bool grid[50][50];
bool visited[50][50][4];
queue<state> q;

/* (STATE-SPACE GRAPH)
 * USE METHODS FOR STATE TRANSITIONS AND CHECKING FOR VALIDITY
 */
bool inbounds(int x, int y) { return 1<=x&&x<m&&1<=y&&y<n; }
bool valid(state s) {
	return inbounds(s.x,s.y)&&!grid[s.x-1][s.y-1]&&
				!grid[s.x][s.y-1]&&!grid[s.x-1][s.y]&&!grid[s.x][s.y];
}
state turnRight(state s) { return state(s.x,s.y,(s.dir+1)%4,s.commands+1); }
state turnLeft(state s) { return state(s.x,s.y,(s.dir+3)%4,s.commands+1); }
state move(state s,int d) { return state(s.x+d*dr[s.dir],s.y+d*dc[s.dir],s.dir,s.commands+1); }

/* (GENERAL)
 * RESET DYNAMIC DATA STRUCTURES FOR REUSE BEFORE EACH TEST CASE
 */
void reset() {
	memset(grid,false,sizeof grid);
	memset(visited,false,sizeof visited);
	while(!q.empty()) q.pop();
}

/* (GENERAL)
 * INITIALIZE STATIC DATA STRUCTURES
 */
void init() {
	dir["north"]=0;
	dir["east"]=1;
	dir["south"]=2;
	dir["west"]=3;
}

/* (SINGLE-SOURCE SHORTEST PATH)
 * QUEUE NEIGHBOR IF UNVISITED AND VALID
 */
void process(state s) {
	if(visited[s.x][s.y][s.dir]||!valid(s)) return;
	visited[s.x][s.y][s.dir]=true;
	q.push(s);
}

/* (SSSP ON UNWEIGHTED)
 * QUEUE INITIAL STATE AND PROCESS NEIGHBORS
 * WITH BFS
 */
int bfs() {
	int sx,sy,ex,ey;
	char d[8];
	scanf("%d %d %d %d %s",&sx,&sy,&ex,&ey,d);
	string sdir=d;

	state start(sx,sy,dir[sdir],0);
	q.push(start);
	while(!q.empty()) {
		state s=q.front(); q.pop();
		if(s.x==ex&&s.y==ey) return s.commands;
		state m1=move(s,1),m2=move(s,2),m3=move(s,3);
		process(m1);
		if(valid(m1)) process(m2);
		if(valid(m1)&&valid(m2)) process(m3);
		process(turnLeft(s));
		process(turnRight(s));
	} return -1;
}

int main() {
	vector<int> ans;
	init();
	while(scanf("%d %d",&m,&n),m||n) {
		reset();
		REP(i,0,m) REP(j,0,n) {
			int b; scanf("%d",&b);
			grid[i][j]=(b==1);
		}
		ans.PB(bfs());
	}
	REP(i,0,SZ(ans)) printf("%d\n",ans[i]);
	exit(0);
}
