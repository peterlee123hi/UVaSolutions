#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000

bool isConnected(string a, string b) {
	if(a.length()!=b.length()) return false;
	int diff=0;
	REP(i,0,a.length()) {
		if(a[i]!=b[i]) diff++;
		if(diff>1) return false;
	}
	return true;
}

map< string,vector<string> > AdjList;
vector<string> dict;

void reset() {
	AdjList.clear();
	dict.clear();
}

int bfs(string from, string dest) {
	map< string,int > dist;
	REP(i,0,SZ(dict)) dist[dict[i]]=INF;
	dist[from]=0;
	queue<string> q; q.push(from);
	
	while(!q.empty()) {
		string u=q.front(); q.pop();
		REP(j,0,SZ(AdjList[u])) {
			string v=AdjList[u][j];
			if(dist[v]==INF) {
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(v==dest) return dist[v];
		}
	} return -1;
}

int main() {
	int T,C=0;
	scanf("%d",&T);
	while(T--) {
		reset();
		if(C) printf("\n");

		char temp[21];
		scanf(" %s",temp);
		string word=temp;
		while(word!="*") {
			AdjList[word]=vector<string>(0);
			REP(i,0,SZ(dict))
				if(isConnected(word,dict[i])) {
					AdjList[word].PB(dict[i]);
					AdjList[dict[i]].PB(word);
				}
			dict.PB(word);
			scanf(" %s",temp);
			word=temp;
		} getchar();

		/* //DEBUG
		REP(i,0,SZ(dict)) {
			printf("%s:",dict[i].c_str());
			REP(j,0,SZ(AdjList[dict[i]])) printf(" %s",AdjList[dict[i]][j].c_str());
			printf("\n");
		}*/

		string u,v,line;
		while(getline(cin,line)) {
			if(line.length()<2) break;
			int i=0;
			while(line[i]!=' ') i++;
			u=line.substr(0,i);
			v=line.substr(i+1,line.length()-i-1);
			printf("%s %s %d\n",u.c_str(),v.c_str(),bfs(u,v));
		}
		C++;
	}
	exit(0);
}
