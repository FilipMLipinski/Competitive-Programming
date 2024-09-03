#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;

ll logExp(ll a, ll p){
    ll res = 1;
    while(p>0){
        if(p&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        p = p/2;
    }
    return res;
}

ll solve(vector<ll> a, ll n) {
    ll accum = 0;
    ll q = ((n*(n-1))/2)%MOD;
    ll p = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            accum = a[i];
        }
        else{
            p = (p + (accum*a[i])%MOD)%MOD;
            accum = (accum+a[i])%MOD;
        }
    }
    //cout << p << endl;
    return (p*logExp(q, MOD-2))%MOD;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }        
        cout << solve(a, n) << endl;
    }
    return 0;
}