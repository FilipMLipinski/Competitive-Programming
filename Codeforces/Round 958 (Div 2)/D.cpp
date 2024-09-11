#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node{
    ll value;
    int idx;
    vector<Node*> children;
};

ll oddBFS(vector<Node>& tree){
    vector<bool> seen(tree.size(), false);
    ll oddscore = 0;
    vector<Node*> generation;
    generation.push_back(&tree[0]);
    seen[tree[0].idx]=true;
    bool oddgeneration = true;
    while(!generation.empty()){
        vector<Node*> newgeneration;
        for(Node* n : generation){
            if(oddgeneration) oddscore+=n->value;
            for(Node* child : n->children){
                if(!seen[child->idx]){
                    newgeneration.push_back(child);
                    seen[child->idx]=true;
                }
            }
        }
        generation = newgeneration;
        oddgeneration = !oddgeneration;
    }
    return oddscore;
}

// this solution DOES NOT WORK, will update soon
ll solve(vector<pair<int,int>> edges, vector<ll> a, int n) {
    int e = n-1;
    vector<Node> tree;
    ll totalsum = 0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
        Node n;
        n.value = a[i];
        n.idx = i;
        tree.push_back(n);
    }
    for(int i=0;i<e;i++){
        Node* n1 = &tree[edges[i].first];
        Node* n2 = &tree[edges[i].second];
        n1->children.push_back(n2);
        n2->children.push_back(n1);
    }
    ll oddscore = oddBFS(tree);
    return totalsum + min(oddscore, totalsum-oddscore);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> edges;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n-1;i++){
            int a,b;
            cin >> a;
            cin >> b;
            edges.push_back({a-1, b-1});
        }
        cout << solve(edges, a, n) << endl;
    }
    return 0;
}