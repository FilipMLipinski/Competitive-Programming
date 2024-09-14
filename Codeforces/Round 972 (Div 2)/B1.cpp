#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(ll n, int m, vector<ll>& b, ll d) {
    if(b[0] > d && b[1] > d){
        return min(b[0],b[1])-1;
    }
    if(b[0] < d && b[1] < d){
        return n - max(b[0],b[1]);
    }
    // david is between the teachers;
    ll delta = max(b[0], b[1]) - min(b[0], b[1]);
    if(delta%2==1){
        return (delta-1)/2;
    }
    return delta/2;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        int m, q;
        cin >> n >> m >> q;
        vector<ll> b(m);
        for(int i=0;i<m;i++){
            cin >> b[i];
        }
        for(int i=0;i<q;i++){
            ll d;
            cin >> d;
            cout << solve(n, m, b, d) << endl;
        }
    }
    return 0;
}