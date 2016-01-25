#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

map<string,double> memo;
set<string> table;

void reset() {
	memo.clear();
	table.clear();
}

bool inbounds(int x,int y) { return 0<=x&&x<4&&0<=y&&y<4; }

int dr[]={-1,0,1,0,-1,1,1,-1};
int dc[]={0,1,0,-1,-1,-1,1,1};

char board[4][4];
int x,y;

string serialize() {
	string s="";
	REP(i,0,4) REP(j,0,4) s+=board[i][j];
	return s;
}

char other(char p) {
	if(p=='x') return 'o';
	return 'x';
}

bool isWinningMove(int x,int y,char p) {
	REP(i,0,8) {
		if(inbounds(x+dr[i],y+dc[i])&&inbounds(x+dr[i]*2,y+dc[i]*2)&&inbounds(x+dr[i]*3,y+dc[i]*3)
			&&board[x+dr[i]][y+dc[i]]==p&&board[x+dr[i]*2][y+dc[i]*2]==p&&board[x+dr[i]*3][y+dc[i]*3]==p||
			inbounds(x+dr[i]*-1,y+dc[i]*-1)&&inbounds(x+dr[i]*1,y+dc[i]*1)&&inbounds(x+dr[i]*2,y+dc[i]*2)
			&&board[x+dr[i]*-1][y+dc[i]*-1]==p&&board[x+dr[i]*1][y+dc[i]*1]==p&&board[x+dr[i]*2][y+dc[i]*2]==p||
			inbounds(x+dr[i]*-2,y+dc[i]*-2)&&inbounds(x+dr[i]*-1,y+dc[i]*-1)&&inbounds(x+dr[i]*1,y+dc[i]*1)
			&&board[x+dr[i]*-2][y+dc[i]*-2]==p&&board[x+dr[i]*-1][y+dc[i]*-1]==p&&board[x+dr[i]*1][y+dc[i]*1]==p)
			return true;
	} return false;
}

double probOfWinning(char p) {
	string s=serialize();
	if(table.find(s)!=table.end()) return memo[s];

	double prob=0;
	REP(i,0,4) REP(j,0,4) {
		if(board[i][j]=='.') {
			if(isWinningMove(i,j,p)) {
				//printf("Prob of %c winning: %0.5f\n",p,1-prob);
				//REP(i,0,4) { REP(j,0,4) printf("%c",board[i][j]); printf("\n"); } printf("\n");
				table.insert(s); memo[s]=1;
				return 1;
			}
			board[i][j]=p;
			prob=max(prob,1-probOfWinning(other(p)));
			board[i][j]='.';
		}
	}
	//printf("Prob of %c winning: %0.5f\n",p,1-prob);
	//REP(i,0,4) { REP(j,0,4) printf("%c",board[i][j]); printf("\n"); } printf("\n");
	table.insert(s); memo[s]=prob;
	return prob;
}

bool hasForcedWin() {
	REP(i,0,4) REP(j,0,4)
		if(board[i][j]=='.') {
			board[i][j]='x';
			if(isWinningMove(i,j,'x')||probOfWinning('o')==0) {
				x=i; y=j; return true;
			}
			board[i][j]='.';
		}
	return false;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	char c; scanf(" %c",&c);
	while(c=='?') {
		reset();
		REP(i,0,4) REP(j,0,4) scanf(" %c",&board[i][j]);
		scanf(" %c",&c);
		if(hasForcedWin()) printf("(%d,%d)\n",x,y);
		else printf("#####\n");
	} exit(0);
}
