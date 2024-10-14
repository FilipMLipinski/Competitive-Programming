#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll MOD = 1e9+7;

ll pow(ll a, ll p){
    a = a%MOD;
    if(p==0) return 1;
    else if (p%2==0) return (pow((a*a)%MOD, p/2))%MOD;
    else return (a*(pow((a*a)%MOD, (p-1)/2))%MOD)%MOD;
}

void solve(int t, ll* n, ll* k) {
    for(int i =0;i<t;i++){
        cout << pow(2, k[i]) << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    ll n[t];
    ll k[t];
    for(int i=0;i<t;i++){
        cin >> n[i];
    }
    for(int i=0;i<t;i++){
        cin >> k[i];
    }
    solve(t, n, k);
    return 0;
}