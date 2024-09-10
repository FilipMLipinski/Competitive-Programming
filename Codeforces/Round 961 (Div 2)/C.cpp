#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int powdiff(ll a, ll b){
    int count = 0;
    while(a<b){
        a*=a;
        count++;
    }
    return count;
}

int alt_powdiff(ll a, ll b){
    // biggest k s.t. a^2k <= b
    int count = 1;
    a = a*a;
    while(a <= b){
        a*=a;
        count++;
    }
    return count-1;

}

ll solve(int n, vector<ll> a){
    vector<int> p(n ,0);
    int start = 0;
    while(start < n){
        if(a[start]==1) start++;
        else break;
    }
    ll ret = 0;
    ll curr = 0;
    for(int i=start+1;i<n;i++){
        if(a[i]==1) return -1;
        if(a[i]>=a[i-1]){
            p[i] = -alt_powdiff(a[i-1], a[i]);
        }
        else{
            p[i] = powdiff(a[i], a[i-1]);
        }
        curr = max((ll)0, curr + p[i]);
        ret += curr;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}