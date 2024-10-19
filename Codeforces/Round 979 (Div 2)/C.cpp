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

string solve(int n, string& s) {
    if(s[0]=='1' || s[n-1]=='1') return "YES";
    char prev = '0';
    for(int i=0;i<n;i++){
        if(s[i]=='1' && prev=='1'){
            return "YES";
        }
        prev=s[i];
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n, s) << endl;
    }
    return 0;
}