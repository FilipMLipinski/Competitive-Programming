#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll solve(ll m) {
    // from 0 to m inclusive;
    if(m==0) return 1;
    ll potent = sqrt(2*m);
    if(potent*(potent+1)/2 <= m) return potent+1;
    else return potent;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << solve(r-l) << endl;
    }
    return 0;
}