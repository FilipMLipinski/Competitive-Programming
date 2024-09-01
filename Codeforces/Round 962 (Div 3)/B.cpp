#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(vector<string> & grid, int k) {
    for(int i=0;i<grid.size();i+=k){
        string ret;
        for(int j=0;j<grid.size();j+=k){
            ret.push_back(grid[i][j]);
        }
        cout << ret << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<string> grid(n);
        for(int i=0;i<n;i++){
            cin >> grid[i];
        }        
        solve(grid, k);
    }
    return 0;
}