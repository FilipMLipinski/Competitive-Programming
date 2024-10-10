#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

string solve(int n, vector<pair<int, int>> E, int u, int v) {
    return "Alice"
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> E(n-1);
        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            E[i] = {a-1,b-1};
        }
        int u, v;
        cin >> u >> v;
        cout << solve(n, E, u-1, v-1) <<endl;
    }
    return 0;
}