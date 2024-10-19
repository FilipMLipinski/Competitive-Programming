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

string solve(int n, int q, int *p, string s, int *Q) {
    vector<bool> ls(n, false);
    int mx = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        mx = max(mx, p[i]);
        cnt++;
        if(mx==cnt){
            ls[i] = true;
        }
    }
    int lrc = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='L' && s[i+1]=='R'){
            if(!ls[i]){
                lrc++;
            }
        }
    }
    string ret = "";
    for(int i=0;i<q;i++){
        int qi = Q[i]-1;
        if(s[qi]=='R'){
            if(s[qi-1]=='L' && !ls[qi-1]) lrc--;
            if(s[qi+1]=='R' && !ls[qi]) lrc++;
            s[qi] = 'L';
        }
        else{
            // L->R
            if(s[qi-1]=='L' && !ls[qi-1]) lrc++;
            if(s[qi+1]=='R' && !ls[qi]) lrc--;
            s[qi] = 'R';
        }
        if(lrc==0){
            ret += "YES\n";
        }
        else ret+="NO\n";
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int p[n];
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        string s;
        cin >> s;
        int Q[q];
        for(int i=0;i<q;i++){
            cin >> Q[i];
        }
        cout << solve(n,q,p,s,Q);
    }
    return 0;
}