#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(vector<string> rows, int n) {
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<rows[i].size();j++){
            if(rows[i][j]=='#'){
                cout << j+1 << " ";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> rows(n);
        for(int i=0;i<n;i++){
            cin >> rows[i];
        }        
        solve(rows, n);
    }
    return 0;
}