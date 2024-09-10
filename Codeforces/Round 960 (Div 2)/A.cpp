#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool solve(int n, vector<int> & a) {
    vector<int> c(n+1, 0);
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(c[i]%2) return true;
    }
    return false;
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
        string ans;
        if(solve(n,a)) ans="YES";
        else ans = "NO";
        cout << ans << endl;
    }
    return 0;
}