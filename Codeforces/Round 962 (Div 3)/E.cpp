#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;

ll aux(vector<int> v, int n){
    if(v.size()<2) return 0;
    ll ret = 0;
    ll acum = v[0]+2;
    for(int i=1;i<v.size();i++){
        ret = (ret +((n-v[i]) * acum)%MOD) % MOD;
        acum = (acum + (v[i]+2))%MOD;
    }
    return ret;
}

ll solve(string s) {
    map<int, vector<int>> m;
    int curr = 0;
    m[0].push_back(-1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') curr++;
        else curr--;
        m[curr].push_back(i);
    }
    ll ret = 0;
    for(auto it = m.begin();it!=m.end();it++){
        ret = (ret + aux(it->second, s.size()))%MOD;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solve(s) << endl;        
    }
    return 0;
}