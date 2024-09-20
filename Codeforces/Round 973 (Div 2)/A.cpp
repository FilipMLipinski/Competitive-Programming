#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(ll n, ll x, ll y) {
    if(n%min(x,y)) return n/min(x,y) + 1;
    return n/min(x, y);
}

int main() {
    int t;
    cin >> t;
    while(t--){
       ll n, x,y;
       cin >> n >> x >> y;
       cout << solve(n,x,y) << endl; 
    }
    return 0;
}