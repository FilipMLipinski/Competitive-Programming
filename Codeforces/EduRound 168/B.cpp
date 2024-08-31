#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool fitsPattern(string u, string d){
    if(u == "..." && d =="x.x") return true;
    if(d == "..." && u=="x.x") return true;
    return false;
}

int solve(string & u, string & d) {
    int counter = 0;
    if(u.size()<3) return 0;
    for(int i=0;i<u.size()-2;i++){
        if(fitsPattern(u.substr(i, 3), d.substr(i, 3))){
            counter++;
        }
    }
    return counter;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        string u, d;
        cin >> u >> d;
        cout << solve(u, d) << endl;
    }
    return 0;
}