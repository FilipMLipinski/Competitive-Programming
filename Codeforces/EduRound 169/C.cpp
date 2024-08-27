#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve(vector<ll> a, ll k) {
    sort(a.begin(), a.end());
    auto it = a.rbegin();
    bool at = true;
    ll last = 0;
    ll ret = 0;
    while(it!=a.rend()){
        if(at){
            last = *it;
            ret += last;
        }
        else{
            ll diff = last - *it;
            if(k>=diff){
                ret -= last;
                k -= diff;
            }
            else{
                ret -= *it + k;
                k = 0;
            }
        }
        at = !at;
        it++;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        ll k;
        cin >> n;
        cin >> k;
        vector<ll> a(n);
        for(int j =0; j<n; j++){
            cin >> a[j];
        }
        cout<<solve(a, k)<<endl;
    }
    return 0;
}