#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Node{
    ll v;
    vector<int> children;
};

ll solveRecur(int n, vector<Node> & nodes){
    if(n==0 && !nodes[n].children.empty()){
        ll minim = 3e9;
        for(int i=0;i<nodes[n].children.size();i++){
            minim = min(minim, solveRecur(nodes[n].children[i], nodes));
        }
        //cout << "node " << n << " gives: " << nodes[n].v+minim << endl;
        return nodes[n].v + minim;       
    }
    if(nodes[n].children.empty()){
        //cout << "node " << n << " gives: " << nodes[n].v << endl;
        return nodes[n].v;
    }
    else{
        ll minim = 3e9;
        for(int i=0;i<nodes[n].children.size();i++){
            ll c = solveRecur(nodes[n].children[i], nodes);
            ll balanced = (nodes[n].v + c) /2;
            minim = min(minim, min(c,balanced));
        }
        //cout << "node " << n << " gives: " << nodes[n].v+minim << endl;
        return minim;
    }
}

ll solve(vector<ll> & vals, vector<int> & parents) {
    Node root;
    root.v = vals[0];
    vector<Node> nodes;
    nodes.push_back(root);
    for(int i=0;i<parents.size();i++){
        Node newnode;
        newnode.v = vals[i+1];
        nodes.push_back(newnode);
    }
    //cout << "node num: " << nodes.size() << endl;
    for(int i=0;i<parents.size();i++){
        (nodes[parents[i]-1].children).push_back(i+1);
    }
    return solveRecur(0, nodes);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<ll> vals(n);
        vector<int> parent(n-1);
        for(int j=0;j<n;j++){
            cin >> vals[j];
        }
        for(int j=0;j<n-1;j++){
            cin >> parent[j];
        }
        cout << solve(vals, parent) << endl;
    }
    return 0;
}