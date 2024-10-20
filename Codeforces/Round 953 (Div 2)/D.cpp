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

string solve(int n, ll c, ll *a) {
    a[0] += c;
    ll psum = 0;
    ll p[n];
    for(int i=0;i<n;i++){
        psum += a[i];
        p[i] = psum;
        // cout << p[i] << " ";
    }
    // cout << endl;
    ll h = 0;
    ll idx = n;
    int mx[n];
    for(int i=n-1;i>=0;i--){
        if(a[i] >= h){
            h = a[i];
            idx = i;
        }
        mx[i] = idx;
        // cout << mx[i] << " ";
    }
    // cout << endl;
    string ret = "";
    for(int i=0;i<n;i++){
        if(mx[0]==i){
            ret += "0 ";
        }
        else if(p[i] >= a[mx[i]]){
            ret += to_string(i) + " ";
        }
        else{
            ret += to_string(i+1) + " "; 
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll c;
        cin >> c;
        ll a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << solve(n, c, a) << endl;
    }
    return 0;
}