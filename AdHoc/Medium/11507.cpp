#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define REP(i,a,n) for(long i=a;i<n;i++)

int L;
string dir, wire;
map< string, map<string, string> > bends;
 
int main() {
    bends["+x"]["+y"] = "+y";
    bends["+x"]["-y"] = "-y";
    bends["+x"]["+z"] = "+z";
    bends["+x"]["-z"] = "-z";
    bends["-x"]["+y"] = "-y";
    bends["-x"]["-y"] = "+y";
    bends["-x"]["+z"] = "-z";
    bends["-x"]["-z"] = "+z";
    bends["+y"]["+y"] = "-x";
    bends["+y"]["-y"] = "+x";
    bends["+y"]["+z"] = "+y";
    bends["+y"]["-z"] = "+y";
    bends["-y"]["+y"] = "+x";
    bends["-y"]["-y"] = "-x";
    bends["-y"]["+z"] = "-y";
    bends["-y"]["-z"] = "-y";
    bends["+z"]["+y"] = "+z";
    bends["+z"]["-y"] = "+z";
    bends["+z"]["+z"] = "-x";
    bends["+z"]["-z"] = "+x";
    bends["-z"]["+y"] = "-z";
    bends["-z"]["-y"] = "-z";
    bends["-z"]["+z"] = "+x";
    bends["-z"]["-z"] = "-x";
 
    while(scanf("%d",&L),L) {
        wire = "+x";
        REP(i,0,L-1) {
            cin >> dir;
            if(dir != "No")
                wire = bends[wire][dir];
        }
        cout << wire << endl;
    }
}
