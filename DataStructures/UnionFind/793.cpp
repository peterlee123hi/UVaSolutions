#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<int> vi;
#define REP(i,a,n) for(int i=a;i<n;i++)

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int n) {
		rank.assign(n,0);
		p.assign(n,0);
		REP(i,0,n) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]) {
				p[y] = p[x];
			} else {
				p[x] = p[y];
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int main() {
	int N,c=0;
	string s;
	scanf("%d",&N);
	while(N--) {
		if(c++)
			printf("\n");
		int n; 
		scanf("%d\n",&n);
		UnionFind uf(n);
		
		char c;
		int a,b,good=0,bad=0;
		while(getline(cin,s),s!="") {
			stringstream ss(s);
			ss >> c >> a >> b;
			a--; b--;
			if(c=='c')
				uf.unionSet(a,b);
			else
				if(uf.isSameSet(a,b))
					good++;
				else 
					bad++;
		}
		printf("%d,%d\n",good,bad);
	}
	return 0;
}
