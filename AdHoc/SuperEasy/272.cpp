#include <cstdio>
using namespace std;

int main() {
	char in;
	bool e = true;
	while(scanf("%c", &in) != EOF) {
		if(in == '"') {
			printf((e)?"``":"''");
			e = !e;
		} else
			printf("%c", in);
	}
	return 0;
}
