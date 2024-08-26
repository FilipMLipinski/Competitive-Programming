#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node{
    long long plug;
    long long yield;
    vector<Node*> offspring;
    bool seen;
};

void resetGraph(vector<Node>& g){
    for(int i = 0; i<g.size(); i++){
        g[i].seen = false;
    }
}

void printNode(Node n){
    cout << "plug: " << n.plug << " yield: " << n.yield;
    // cout<< " offspring: ";
    // int i = 1;
    // for(Node* c: n.offspring){
    //     cout << "(";
    //     printNode(*c);
    //     cout << ")";
    // }
    cout<<endl;
}

long long BFS(vector<Node> & g, long long x){
    queue<Node*> frontier;
    long long best = x;
    for(int i = 0; i<g.size(); i++){
        if(g[i].plug == x){
            frontier.push(&g[i]);
            g[i].seen = true;
            // cout<<"initialising frontier: ";
            // printNode(g[i]);
        }
    }
    while(!frontier.empty()){
        Node* n = frontier.front();
        // cout << "popping from frontier: ";
        // printNode(*n);
        frontier.pop();
        best = max(best, (*n).yield);
        for(Node* child: (*n).offspring){
            if(!(*child).seen){
                frontier.push(child);
                (*child).seen = true;
            }
        }
    }
    return best;
}

Node readSeq(vector<long long>& l){
    Node n;
    sort(l.begin(), l.end());
    auto iter = l.begin();
    long long prev = -1;
    bool plugged = false;
    while(iter!=l.end()){
        if(!((*iter)==prev || *iter==prev+1)){
            if(!plugged && (*iter)==prev+2){
                plugged = true;
                n.plug = prev+1;
            }
            else{
                break;
            }
        }
        prev = *iter++;
    }
    if(!plugged){
        n.plug = prev+1;
        n.yield = prev+2;
    }
    else{
        n.yield = prev+1;
    }
    return n;
}

set<long long> linkNodes(vector<Node> & g){
    // also outputs the plugs that are doubled
    set<long long> doubles;
    for(int n1 = 0; n1<g.size(); n1++){
        for(int n2 = 0; n2<g.size(); n2++){
            if(n1!=n2){
                if(g[n1].yield == g[n2].plug){
                    g[n1].offspring.push_back(&(g[n2]));
                }
                if(g[n1].plug == g[n2].plug){
                    doubles.insert(g[n1].plug);
                }
            }
        }
    }
    return doubles;
}

// this solution gives time limit exceeded on test 22.
long long solve(vector<vector<long long>>& ls, long long m) {
    vector<Node> g;
    long long upper_bound = 0;
    long long max_plug = 0;
    for(vector<long long> l: ls){
        Node n = readSeq(l);
        upper_bound = max(n.yield, upper_bound);
        max_plug = max(n.plug, max_plug);
        g.push_back(n);
    }
    set<long long> doubles;
    doubles = linkNodes(g);
    long long f_i_max = 0;
    for(long long i: doubles){
        f_i_max = max(f_i_max, BFS(g, i));
        resetGraph(g);
    }
    // for(Node n: g){
    //     printNode(n);
    // }
    long long x = 0;
    long long res = 0;
    while(x < upper_bound && x<=m){
        res += max(max(BFS(g, x), f_i_max), max_plug);
        //cout << res<<endl;
        resetGraph(g);
        x++;
    }
    if(x<=m){
        res += ((x+m)*(m-x+1))/2;
    }
    return res;
}

void testSeq(){
    vector<long long> l = {7,3,6,0,3};
    Node s = readSeq(l);
    cout << "plug: " << s.plug << " yield: " << s.yield<<endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i< t; i++) {
        int n;
        long long m;
        cin >> n >> m;
        vector<vector<long long>> ls(n);
        for(int j = 0; j<n; j++){
            int l_len;
            cin >> l_len;
            vector<long long> l(l_len);
            for(int k = 0; k<l_len; k++){
                cin >> l[k];
            }
            ls[j] = l;
        }
        cout << solve(ls, m) << endl;
    }
    //testSeq();
    return 0;
}