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

int solve(int n, int *a){
    if(n==1){
        return 0;
    }
    int mini = 2000;
    int maxi = -1;
    for(int i=0;i<n;i++){
        mini = min(a[i], mini);
        maxi = max(a[i], maxi);
    }
    return (maxi - mini)*(n-1);

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
        cout << solve(n,a) << endl;
    }
    return 0;
}