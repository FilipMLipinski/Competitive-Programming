#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(string s, string t) {
    int i = 0;
    int similar = 0;
    while(i < s.size() && i < t.size()){
        if(s[i]!=t[i]){
            break;
        }
        else{
            similar++;
            i++;
        }
    }
    if(similar > 0) return s.size() + t.size() - similar + 1;
    else return s.size() + t.size();
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        cout << solve(s,t) << endl;
    }
    return 0;
}