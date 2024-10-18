#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdint>

using namespace std;
typedef long long ll;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // credit goes to http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int solve(int n, int *a) {
    unordered_map<int, pair<int,int>, custom_hash> t;
    unordered_map<int, vector<int>, custom_hash> m;
    for(int i=0;i<n;i++){
        m[a[i]].push_back(i);
    }
    int l = n+1; //max_int
    int r = -1; //min_int
    bool uninit = true;
    for(int i=1;i<=n;i++){
        if(m.count(i)==0){
            continue;
        }
        else{
            l = min(l,m[i][0]);
            r = max(r,m[i][m[i].size()-1]);
            t[i] = {l, r};
            // check if the property holds
            if(i < r-l+1) return 0;
        }
    }
    // for(auto it = t.begin(); it!=t.end();it++){
    //     cout << it->first << ". l: " << it->second.first << " r: " << it->second.second<< endl;
    // }
    int L = 0;
    int R = n-1;
    for(auto it=t.begin();it!=t.end();it++){
        if(L>R) break;
        int lx = it->second.second - it->first + 1;
        int rx = it->first + it->second.first - 1;
        // cout << it->first << " lx: " << lx << " rx: " << rx << endl;
        L = max(L, lx);
        R = min(R, rx);
    }
    if(L>R){
        return 0;
    }
    return R-L+1;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
           cin >> a[i]; 
        }        
        cout << solve(n, a) << endl;
    }
    return 0;
}