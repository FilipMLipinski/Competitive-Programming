#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(vector<int> p, string c, int n) {
    vector<bool> seen(n, false);
    vector<int> ret(n);
    for(int i=0;i<n;i++){
        if(!seen[i]){
            // find the eq class
            int counter = 0;
            int j = i;
            while(!seen[j]){
                seen[j] = true;
                if(c[j]=='0') counter++;
                j = p[j]-1;
            }
            j = i;
            ret[j] = counter;
            j = p[j] - 1;
            while(j!=i){
                ret[j] = counter;
                j = p[j]-1;
            }
        }
    }
    for(int i: ret){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }        
        string c;
        cin >> c;
        solve(p, c, n);
    }
    return 0;
}