#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string word; int cn=1;
	while(cin>>word,word!="*") {
		if(word=="Hajj") printf("Case %d: Hajj-e-Akbar\n",cn++);
		else printf("Case %d: Hajj-e-Asghar\n",cn++);
	}
	exit(0);
}
