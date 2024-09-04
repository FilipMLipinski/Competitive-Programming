#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll udiv(ll a, ll b){
    if(a%b!=0){
        return a/b + 1;
    }
    return a/b;
}

int solve(ll x, ll y, ll k) {
    ll ret = 0;
    ll tox = udiv(x, k);
    ll toy = udiv(y,k);
    if(x!=0 && y!=0){
        if(toy >= tox){
            return 2*toy;
        }
        else return 2*tox -1;
    }
    if(x==0){
        if(y==0){
            return 0;
        }
        return toy*2;
    }
    if(y==0){
        return tox*2 -1;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll x,y,k;
        cin >> x >> y >> k;
        cout << solve(x,y,k) <<endl;
    }
    return 0;
}