#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

vector<int> getPathNodes(int n, unordered_map<int, vector<int>> N, int u){
    // numbers of nodes between 0 and u.
    vector<int> ret;
    unordered_map<int, int> parent;
    vector<bool> seen(n);
    list<int> frontier;
    frontier.push_back(0);
    seen[0] = true;
    while(!frontier.empty()){
        int curr = frontier.pop_front();
        for(int child : N[curr]){
            if(!seen[child]){
                parent[child] = curr;
                frontier.push_back(child);
                seen[child]=true;
            }
        }
    }
    
}

string solve(int n, vector<pair<int, int>>& E, int u) {
    // first find the nodes on the path between 1 and u.
    unordered_map<int, vector<int>> N;
    for(pair<int, int> e : E){
        N[e.first].push_back(e.second);
        N[e.second].push_back(e.first);
    }
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
        cout << solve(n, E, u-1) <<endl;
    }
    return 0;
}