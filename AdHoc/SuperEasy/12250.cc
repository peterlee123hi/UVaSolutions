#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define REP(i,a,n) for(int i=a;i<n;i++)

int main() {
	int CN=1;
	string word;
	cin>>word;
	while(word!="#") {
		printf("Case %d: ",CN++);
		if(word=="HELLO")
			printf("ENGLISH");
		else if(word=="HOLA")
			printf("SPANISH");
		else if(word=="HALLO")
			printf("GERMAN");
		else if(word=="BONJOUR")
			printf("FRENCH");
		else if(word=="CIAO")
			printf("ITALIAN");
		else if(word=="ZDRAVSTVUJTE")
			printf("RUSSIAN");
		else
			printf("UNKNOWN");
		printf("\n");
		cin>>word;
	}
	exit(0);
}
