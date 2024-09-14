#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

string solve(int n) {
    string ret;
    string cs = "aeiou";
    int baseline = n/5;
    int addit = n%5;
    for(int c=0;c<5;c++){
        ret+= string(baseline, cs[c]);
        if(addit>0){ret += cs[c]; addit--;}
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;        
    }
    return 0;
}