#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0){
        return b;
    }
    else{
        return gcd(b%a, a);
    }
}

void printV(vector<ll> & c){
    for(ll i : c){
        cout << i << " ";
    }
    cout << endl;
}

ll solve(vector<ll> & c, ll a, ll b) {
    if(c.size() == 1){
        return 0;
    }
    ll d = gcd(a,b);
    if(d==1){
        return 0;
    }
    //cout << "array: ";
    //printV(c);
    auto it = c.begin();
    while(it!=c.end()){
        *it = (*it)%d;
        it++;
    }
    ll maxgap = 0;
    //cout << "d: "<< d << endl;
    sort(c.begin(), c.end());
    //cout << "circle: ";
    //printV(c);
    ll prev = 0;
    for(auto itr = c.begin(); itr!=c.end(); itr++){
        maxgap = max(maxgap, (*itr) - prev);
        prev = (*itr);
    }
    return d - max(maxgap, d - (c[c.size()-1] - c[0]));
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        ll a,b;
        cin >> n >> a >> b;
        vector<ll> c(n);
        for(int j =0; j<n; j++){
            cin >> c[j];
        }
        cout << solve(c, a, b) << endl;

    }
    return 0;
}