#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

void printS(set<int> &s){
    for(auto it=s.begin();it!=s.end();++it){
        cout << *it << " ";
    }
    cout << endl;
}

void printV(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

ll solve(int n, vector<int> &a) {
    if(n==1) return a[0];
    ll ret = 0;
    set<int> s = {0};
    vector<int> m(n+1, 0);
    vector<int> p(n);
    for(int i=0;i<n;i++){
        ret += a[i];
        if(m[a[i]]==0){
            m[a[i]]++;
        }
        else if(m[a[i]]==1){
            s.insert(-a[i]);
            m[a[i]]++;
        }
        p[i] = *(s.begin())*(-1);
    }
    s = {0};
    for(int i=0;i<n+1;i++){
        m[i]=0;
    }
    //printV(p);
    // invariant: p[i] is a new value;
    for(int i=0;i<n;i++){
        ret += p[i];
        if(m[p[i]]==0) m[p[i]]++;
        else if(m[p[i]]==1){
            s.insert(-p[i]);
            m[p[i]]++;
        }
        p[i] = *(s.begin())*(-1);
    }
    //printV(p);
    // now just add the cumulated prefix sum;
    int mult = 1;
    for(int i=n-1;i>=0;i--){
        if(p[i]==0) break;
        ret+= (ll)p[i]*(ll)mult;
        mult++;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }        
        cout << solve(n,a) << endl;
    }
    return 0;
}