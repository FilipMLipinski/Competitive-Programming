#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

string solve(string s) {
    string ret;
    char prev = 'X';
    bool sameFound = false;
    int sameidx;
    for(int i=0;i<s.size();i++){
        if(s[i] == prev){
            sameFound=true;
            sameidx = i-1;
            break;
        }
        prev = s[i];
    }
    if(sameFound){
        ret += s.substr(0, sameidx + 1);
        char newc = (s[sameidx] - 'a' + 1)%26 + 'a';
        ret += newc;
        ret += s.substr(sameidx + 1, s.size() - sameidx - 1);
        return ret;
    }
    ret.push_back(s[0]);
    char newc = (s[0] - 'a' + 1)%26 + 'a';
    if(s.size()==1) return ret+newc;
    if(s[1]==newc){
        newc = (s[0] - 'a' + 2)%26 + 'a';
    }
    ret.push_back(newc);
    ret += s.substr(1, s.size()-1);
    return ret;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}