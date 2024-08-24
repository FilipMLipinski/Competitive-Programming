#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
void solve(string & s, string & t) {
    int i = 0;
    int j =0;
    while(i<s.size() && j<t.size()){
        if(s[i] == t[j] || s[i]=='?'){
            if(s[i]=='?') s[i] = t[j];
            i++;
            j++;
        }
        else i++;
    }
    if(i==s.size() && j!=t.size()){
        cout << NO << endl;
        return;
    }
    for(int k = 0; k<s.size(); ++k){
        if(s[k] == '?') s[k]='a';
    }
    cout << YES << endl;
    cout << s << endl;
    return;


}

int main() {
    int n;
    cin >> n;
    REP (i, n) {
        string s;
        string t;
        cin >> s;
        cin >> t;
        solve(s,t);
    }
    return 0;
}