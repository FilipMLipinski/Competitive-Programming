#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef long long ll;

int solve(string & s) {
    stack<int> st;
    int ret = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='_'){
            if(st.empty()) st.push(i);
            else{
                ret += i - st.top();
                st.pop();
            }
        }
        else if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            ret += i-st.top();
            st.pop();
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}