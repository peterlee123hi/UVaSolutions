#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FI first
#define SE second

vii d;
vector<bool> used;
int n,m,i1,i2,d1,d2;
bool found;

int board[20];

void reset() {
	scanf("%d %d %d %d %d",&m,&i1,&i2,&d1,&d2);
	d.clear();
	used.clear();
	used.assign(m,false);
	REP(i,0,m) {
		int p,q; scanf("%d %d",&p,&q);
		d.PB(ii(p,q));
	}
	found=false;
}

void backtrack(int i) {
	if(found) return;
	if(i==0) {
		//board[0]=i1;
		//backtrack(1);
		board[0]=i2;
		backtrack(1);
	} else if(i==n+1) {
		if(board[n]==d1/*||board[n]==d2*/) {
			found=true;
			//REP(j,0,n+1) printf("%d ",board[j]); printf("\n");
		}
	} else {
		REP(j,0,m) {
			if(board[i-1]==d[j].FI&&!used[j]) {
				board[i]=d[j].SE;
				used[j]=true;
				backtrack(i+1);
				used[j]=false;
			}
			if(board[i-1]==d[j].SE&&!used[j]) {
				board[i]=d[j].FI;
				used[j]=true;
				backtrack(i+1);
				used[j]=false;
			}
		}
	}
}

int main() {
	while(scanf("%d",&n),n) {
		reset();
		backtrack(0);
		printf("%s\n",(found)?"YES":"NO");
	}
	exit(0);
}
