#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node{
    int idx;
    vector<Node*> children;
};

string doubleBFS(vector<Node>& g, int a, int b){
    vector<Node*> af;
    vector<Node*> bf;
    vector<bool> seen(g.size(), false);
    af.push_back(&g[a]);
    seen[a] = true;
    bf.push_back(&g[b]);
    seen[b] = true;
    while(true){
        if(af.empty()) return "Bob";
        // Alice moves
        vector<Node*> newaf;
        for(Node* node : af){
            // cout << "Alice at: " << node->idx << endl;
            for(Node* child : node->children){
                if(!seen[child->idx]){
                    newaf.push_back(child);
                    seen[child->idx] = true;
                }
            }
        }
        af = newaf;
        if(bf.empty()) return "Alice";
        vector<Node*> newbf;
        for(Node* node : bf){
            // cout << "Bob at: " << node->idx << endl;
            for(Node* child : node->children){
                if(!seen[child->idx]){
                    newbf.push_back(child);
                    seen[child->idx] = true;
                }
            }
        }
        bf = newbf;
    }
    return "Fault";
}

string solve(int n, vector<pair<int, int>> E, int u, int v) {
    vector<Node> G(n);
    for(int i=0;i<n;i++){
        Node node;
        node.idx = i;
        G[i] = node;
    }
    for(int i=0;i<n-1;i++){
        G[E[i].first].children.push_back(&G[E[i].second]);
        G[E[i].second].children.push_back(&G[E[i].first]);
    }
    return doubleBFS(G, 0, u);
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