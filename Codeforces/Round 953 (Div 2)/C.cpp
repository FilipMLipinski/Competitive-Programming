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

string solve(ll n, ll k) {
    if(n==1) return k==0 ? "YES\n1" : "NO";
    if(k%2==1) return "NO";
    ll mx;
    if(n%2==0){
        ll mid = n/2;
        ll bot = ((1+mid)*mid)/2;
        ll top = ((mid+1+n)*mid)/2;
        mx = 2*(top-bot);
    }
    else{
        ll mid = n/2;
        ll bot = ((1+mid)*mid)/2;
        ll top = ((mid+2+n)*mid)/2;
        mx = 2*(top-bot);
    }
    if(k>mx) return "NO";
    string ret = "YES\n";
    if(k==0){
        for(ll i=1;i<=n;i++){
            ret += to_string(i) + " ";
        }
        return ret;
    }
    ll left = 1;
    ll right = n+1;
    ll accum = -1;
    ll last;
    while(true){
        if(k/2 > accum + right-1){
            left++;
            right--;
            accum-=left;
            accum+=right;
        }
        else{
            last = k/2 - accum;
            break;
        }
    }
    // cout << "left: " << left << " last: " << last << " right: " << right << endl;
    for(ll i=1;i<=n;i++){
        if (i<left){
            ret += to_string(right + i - 1);
        }
        else if(i==left){
            ret += to_string(last);
        }
        else if(i==last){
            ret += to_string(left);
        }
        else if(i>=right){
            ret += to_string(i-right + 1);
        }
        else ret += to_string(i);
        ret += " ";
        
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
       ll n;
       ll k;
       cin >> n >> k;
       cout << solve(n,k) << endl; 
    }
    return 0;
}