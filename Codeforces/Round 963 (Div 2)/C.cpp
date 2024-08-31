#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;
typedef long long ll;

ll findP(ll k, ll mx, ll a){
    // p is an even number such that [a + pk, a+(p+1)k)
    // shares any number with [mx, mx+k)
    // idea: p is the largest even number s.t. a+pk is less than mx+k
    // pk < mx+k-a
    // p < (mx+k-a)/k
    ll p = (mx+k-a)/k;
    if(p%2){
        --p;
    }
    else if(p*k + a == mx+k){
        return -1;
    }
    return p;

}

ll solve(vector<ll> & as, ll mx, ll k) {
    vector<ll> ps;
    for(int i=0;i<as.size();i++){
        ll p = findP(k, mx, as[i]);
        if(p == -1) return -1;
        ps.push_back(p);
    }
    // our interval of search is [s, e)
    ll s = mx;
    ll e = mx+k;
    for(int i = 0; i<as.size();i++){
        ll p = ps[i];
        s = max(s, p*k + as[i]);
        e = min(e, (p+1)*k + as[i]);
        if(s>=e){
            return -1;
        }
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> as(n);
        ll mx = 0;
        for(int j =0;j<n;j++){
            cin >> as[j];
            mx = max(mx, as[j]);
        }
        cout << solve(as, mx, k) << endl;
    }
    return 0;
}