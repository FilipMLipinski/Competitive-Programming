#include <string>
#include <vector>
#include <iostream>

using namespace std;

const string YES = "YES";
const string NO = "NO";
bool solve(string s) {
    return s[0]!=s[s.size()-1];
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >>n;
        string s;
        cin >> s;
        if(solve(s)) cout<<YES<<endl;
        else cout<<NO<<endl;
    }
    return 0;
}