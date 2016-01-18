#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
typedef set<int> si;
#define REP(i,a,n) for(int i=a;i<n;i++)

int* circle;
int n;
si used;

bool is_prime(int x)
{
  if(x<=1) return false;
  if(x<=3) return true;
  if (!(x%2) || !(x%3)) return false;
  int s=(int)(sqrt((double)(x)))+1;
  for(int i=5;i<=s;i+=6)
  {
    if (!(x%i) || !(x%(i+2))) return false;
  }
  return true;
}

void output() {
	REP(i,0,n) {
		if(i==0)
			printf("%d",circle[i]);
		else
			printf(" %d",circle[i]);
	}
	printf("\n");
}

void backtrack(int i,int x) {
	if(i==n-1) {
		if(n==1||is_prime(x+circle[0])) {
			circle[i]=x;
			output();
		}
	} else {
		circle[i]=x;
		REP(num,2,n+1) {
			if(used.find(num)==used.end()&&is_prime(num+x)) {
				used.insert(num);
				backtrack(i+1,num);
				used.erase(num);
			}
		}
	}
}

int main() {
	int TC=0;
	used.insert(1);

	while(scanf("%d",&n)!=EOF) {
		if(TC>0) printf("\n");
		printf("Case %d:\n",++TC);
		circle=new int[n];
		backtrack(0,1);
		used.clear();
	}
}
