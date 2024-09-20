#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    if(n==1){
        return a[0];
    }
    if(n==2){
        return a[1]-a[0];
    }
    for(int i = n-3; i>=0; i--){
        a[n-2] -= a[i];
    }
    return a[n-1] - a[n-2];
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