#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

int solve(string & s, int n) {
    map<char, int> m;
    for(int i = 0; i < n*4; i++){
        m[s[i]]++;
    }
    return min(m['A'], n) + min(m['B'], n) + min(m['C'], n) + min(m['D'], n);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, n) << endl;
    }
    return 0;
}