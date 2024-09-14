#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<int, int> binsearch(vector<ll>&b, int teachers, ll d){
    // first ->> the previous teacher or -1;
    // second ->> the next teacher or m;
    if(b[0] > d){
        return {-1, 0};
    }
    if(b[teachers-1] < d){
        return {teachers-1, teachers};
    }
    int s = 0;
    int e = teachers;
    // invariant: b[s] < d < b[e];
    while(s+1!=e){
        int m = (s+e)/2;
        if(b[m] < d){
            s = m;
        }
        else{
            e = m;
        }
    }
    return {s, e};
}

ll solve(ll n, int m, vector<ll>& b, ll d) {
    if(b[0] > d){
        return b[0]-1;
    }
    if(b[m-1]<d){
        return n - b[m-1];
    }
    pair<int, int> ts = binsearch(b,m,d);
    ll t1 = b[ts.first];
    ll t2 = b[ts.second];
    ll delta = t2-t1;
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
        sort(b.begin(), b.end());
        for(int i=0;i<q;i++){
            ll d;
            cin >> d;
            cout << solve(n, m, b, d) << endl;
        }
    }
    return 0;
}