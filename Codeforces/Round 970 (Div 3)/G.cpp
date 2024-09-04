#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

int solve(vector<ll> a, int n, ll k) {
    if(n==1){
        if(a[0]>=k) return k-1;
        else return k;
    }
    ll d = a[0];
    for(int i=1;i<n;i++){
        d = gcd(a[i], d);
    }
    ll spaces = (d-1) * (n-1);
    if(k>spaces){
        return d*(n-1)+k-spaces;
    }
    else{
        ll filled = (k-1)/(d-1);
        return k+filled;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i=0; i<n;i++){
            cin >> a[i];
        }        
        cout << solve(a, n, k) << endl;
    }
    return 0;
}