#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool canMedBeX(vector<ll> & a, ll k, ll x){
    vector<int> b(a.size());
    for(int i=0;i<b.size();i++){
        b[i] = (a[i] >= x) ? 1 : -1;
    }
    vector<int> dp(a.size());
    dp[0] = b[0];
    for(int i=1;i<a.size();i++){
        if(i%k == 0){
            dp[i] = max(dp[i-k], b[i]);
        }
        else{
            dp[i] = dp[i-1] + b[i];
            if(i>k){
                dp[i] = max(dp[i], dp[i-k]);
            }
        }
    }
    return dp[a.size()-1]>0;
}

ll solve(vector<ll> & a, ll k, ll maxa, ll mina) {
    // our answer is in the range [min_a, max_a+1)
    maxa++;
    while(mina+1 != maxa){
        ll mid = (mina+maxa)/2;
        if(canMedBeX(a, k, mid)){
            mina = mid;
        }
        else{
            maxa = mid;
        }
    }
    return mina;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        ll maxa = 0;
        ll mina = 2e9;
        for(int j = 0;j<n;j++){
            ll newa;
            cin >> newa;
            a[j] = newa;
            maxa = max(maxa, newa);
            mina = min(mina, newa);
        }
        cout << solve(a, k, maxa, mina) << endl;
    }
    return 0;
}