#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int T,TC=1,n,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&n,&d);
		int stones[n+2];
		char type[n+2];
		stones[0]=0;
		stones[n+1]=d;
		type[0]='B';
		type[n+1]='B';
		REP(i,1,n+1) {
			char c;
			int x;
			scanf(" %c-%d",&c,&x);
			stones[i]=x;
			type[i]=c;
		}
		int max_d=0,cur=0,next=1,pos=0,small_count=0;
		while(cur<n+1) {
			if(type[next]=='S'&&small_count%2==1) {
				next++;
				small_count++;
			}
			max_d=max(max_d,abs(stones[next]-pos));
			pos=stones[next];
			if(type[next]=='S'&&small_count%2==0) {
				stones[next]=-1;
				small_count++;
			}
			cur=next++;
		}
		cur=n+1;
		next=n;
		while(cur>0) {
			while(stones[next]==-1) next--;
			max_d=max(max_d,abs(stones[next]-stones[cur]));
			cur=next--;
		}
		printf("Case %d: %d\n",TC++,max_d);
	}
	return 0;
}
