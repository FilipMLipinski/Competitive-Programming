#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

pair<long long, long long> readSeq(vector<long long>& l){
    pair<long long, long long> n;
    sort(l.begin(), l.end());
    auto iter = l.begin();
    long long prev = -1;
    bool plugged = false;
    while(iter!=l.end()){
        if(!((*iter)==prev || *iter==prev+1)){
            if(!plugged && (*iter)==prev+2){
                plugged = true;
                n.first = prev+1;
            }
            else{
                break;
            }
        }
        prev = *iter++;
    }
    if(!plugged){
        n.first = prev+1;
        n.second = prev+2;
    }
    else{
        n.second = prev+1;
    }
    return n;
}

long long solve(vector<vector<long long>>& ls, long long m) {
    long long upper_bound = 0;
    long long max_plug = 0;
    unordered_map<long long, set<long long>> edges;
    set<long long> doubles; //vertices that have at least two outgoing edges.
    for(vector<long long> l: ls){
        pair<long long, long long> p = readSeq(l);
        upper_bound = max(p.second, upper_bound);
        max_plug = max(p.first, max_plug);
        if(edges.count(p.first)){
            doubles.insert(p.first);
            edges[p.first].insert(p.second);
        }
        else{
            set<long long> s;
            s.insert(p.second);
            edges[p.first] = s;
        }
    }
    vector<long long> f(upper_bound+1, -1);
    long long f_i_max = 0;
    for(long long i = upper_bound; i>=0; i--){
        if(!edges.count(i)){
            f[i] = i;
        }
        else{
            long long best = 0;
            for(long long j : edges[i]){
                best = max(best, f[j]);
            }
            f[i] = best;
            if(doubles.count(i)){
                f_i_max = max(f_i_max, best);
            }
        }
    }
    long long x = 0;
    long long res = 0;
    while(x < upper_bound && x<=m){
        res += max(max(f[x], f_i_max), max_plug);
        x++;
    }
    if(x<=m){
        res += ((x+m)*(m-x+1))/2;
    }
    return res;
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