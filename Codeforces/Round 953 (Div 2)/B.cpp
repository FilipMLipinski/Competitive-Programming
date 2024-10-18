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

ll solve(ll n, ll a, ll b) {
    ll k = b-a+1;
    if(k<=0) return n*a;
    if(k>=n) return ((b+b-n+1)*n)/2;
    else return ((b+b-k+1)*k)/2 + a*(n-k);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n,a,b;
        cin >> n >> a >> b;
        cout << solve(n,a,b)<<endl;
    }
    return 0;
}