#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

void printL(list<bool> l){
    for(auto i=l.begin();i!=l.end();i++){
        cout << *i;
    }
    cout << endl;
}

list<bool> toBin(ll n){
    list<bool> ret;
    while(n>0){
        ret.push_front(n%2);
        n/=2;
    }
    return ret;
}

void solve(ll n) {
    list<bool> bin = toBin(n);
    vector<ll> ret;
    ll currmult = 1;
    ret.push_back(n);
    for(auto i = bin.rbegin();i!=bin.rend();i++){
        if(*i){
            n -= currmult;
            if(n!=0) ret.push_back(n);
            n += currmult;
        }
        currmult*=2;
    }
    cout << ret.size() << endl;
    for(auto i = ret.rbegin();i!=ret.rend();i++){
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}