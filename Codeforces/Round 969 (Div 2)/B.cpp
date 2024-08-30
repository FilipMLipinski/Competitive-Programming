#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

typedef long long ll;

struct Op{
    ll l;
    ll r;
    bool add;
};

using namespace std;

void solve(vector<Op> & v, ll mx) {
    vector<ll> ret;
    for(auto it = v.begin(); it!=v.end(); it++){
        if(it->add){
            if(it->l <= mx && it->r >= mx){
                mx++;
            }
        }
        else{
            if(it->l <= mx && it->r >= mx){
                mx--;
            }
        }
        ret.push_back(mx);
    }
    for(auto it = ret.begin(); it!=ret.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        vector<Op> v;
        int n, m;
        cin >> n >> m;
        ll mx = 0;
        for(int j = 0; j<n; j++){
            ll cand;
            cin >> cand;
            mx = max(mx, cand);
        }
        for(int c = 0; c<m; c++){
            Op op;
            char ch;
            cin >> ch;
            if(ch=='+'){
                op.add = true;
            }
            else{
                op.add = false;
            }
            cin >> op.l;
            cin >> op.r;
            v.push_back(op);
        }
        solve(v, mx);
    }
    return 0;
}