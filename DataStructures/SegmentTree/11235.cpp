#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
#define PB push_back
#define SZ(x) ((int)(x).size())
#define REP(i,a,n) for(int i=a;i<n;i++)

class SegmentTree {
private: vi st, A;
	int n;
	int left (int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if (L == R)
	  		st[p] = L;
		else {
		  	build(left(p) , L			  , (L + R) / 2);
		  	build(right(p), (L + R) / 2 + 1, R		  );
		  	int p1 = st[left(p)], p2 = st[right(p)];
		  	st[p] = compare(p1,p2,0) ? p1 : p2;
  		} 
  	}

  	bool compare(int idx1, int idx2, int i) {
  		return adjusted_val(idx1,i) >= adjusted_val(idx2,i);
  	}

  	bool valid(int idx, int i) {
  		return A[idx]<=idx-i+1;
  	}

  	int rmq(int p, int L, int R, int i, int j) {
		if (i >  R || j <  L) return -1;
		if (L==R) return st[p];
		if (L >= i && R <= j && valid(st[p],i)) return st[p];

		int p1 = rmq(left(p) , L			  , (L+R) / 2, i, j);
		int p2 = rmq(right(p), (L+R) / 2 + 1, R		  , i, j);

		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return compare(p1,p2,i) ? p1 : p2;
  	}

public:
  	int adjusted_val(int idx, int i) {
  		int adj = min(idx-i+1, A[idx]);
  		return adj;
  	}

  	SegmentTree(const vi &_A) {
		A = _A; n = (int)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

  	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int main() {
	int n,q;
	while(scanf("%d",&n),n) { scanf("%d",&q);
		vi A(n,0);
		int prev=-1,count=1;
		REP(i,0,n) {
			int cur; scanf("%d",&cur);
			if(cur!=prev)
				count=1;
			prev=cur;
			A[i]=count++;
		}
		SegmentTree st(A);
		
		int i,j;
		REP(qn,0,q) {
			scanf("%d %d",&i,&j);
			i--; j--;
			int rmq=st.rmq(i,j);
			int adj=st.adjusted_val(rmq,i);
			printf("%d\n",adj);
		}
	}
	return 0;
}
