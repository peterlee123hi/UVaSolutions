#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)
#define PER(i,a,n) for(int i=n-1;i>=a;i--)

map<char,char> mirror;

int main() {
	mirror['A']='A';
	mirror['E']='3';
	mirror['H']='H';
	mirror['I']='I';
	mirror['J']='L';
	mirror['L']='J';
	mirror['M']='M';
	mirror['O']='O';
	mirror['S']='2';
	mirror['T']='T';
	mirror['U']='U';
	mirror['V']='V';
	mirror['W']='W';
	mirror['X']='X';
	mirror['Y']='Y';
	mirror['Z']='5';
	mirror['1']='1';
	mirror['2']='S';
	mirror['3']='E';
	mirror['5']='Z';
	mirror['8']='8';

	string line;
	while(getline(cin,line),line!="") {
		string rev(line.length(),' ');
		int k=0;
		PER(j,0,line.length()) rev[k++]=line[j];
		bool p=true,m=true;
		REP(i,0,line.length()/2+1) {
			if(!p&&!m) break;
			if(rev[i]!=line[i])
				p=false;
			if(mirror[rev[i]]!=line[i])
				m=false;
		}

		if(p&&m)
			printf("%s -- is a mirrored palindrome.\n\n",line.c_str());
		else if(p)
			printf("%s -- is a regular palindrome.\n\n",line.c_str());
		else if(m)
			printf("%s -- is a mirrored string.\n\n",line.c_str());
		else
			printf("%s -- is not a palindrome.\n\n",line.c_str());
	}
	return 0;
}
