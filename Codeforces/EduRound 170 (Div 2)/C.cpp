#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int solve(int n, int k, ll* a) {
    unordered_map<ll, int> m;
    for(int i=0;i<n;i++){
        m[a[i]] += 1;
    }
    int bl = 0;
    while(!m.empty()){
        // calculate the 'lump' starting at first mapping
        auto it = m.begin();
        ll mid = it->first;
        list<int> lump;
        lump.push_back(it->second);
        m.erase(mid);
        // go left
        ll l = 1;
        while(m.count(mid-l)!=0){
            lump.push_back(m[mid-l]);
            m.erase(mid-l);
            l++;
        }
        // go right
        ll r = 1;
        while(m.count(mid+r)!=0){
            lump.push_front(m[mid+r]);
            m.erase(mid+r);
            r++;
        }
        // lump has the whole lump;
        int cand = 0;
        if(lump.size()<=k){
            // let cand be the sum of the lump
            for(auto lit = lump.begin();lit!=lump.end();lit++){
                cand += *lit;
            }           
        }
        else{
            // cand is the best k-length run.
            auto lit = lump.begin();
            int current = 0;
            for(int i=0;i<k;i++){
                current += *lit;
                lit++;
            }
            int cbest = current;
            auto tail = lump.begin();
            while(lit!=lump.end()){
                current -= *tail;
                current += *lit;
                lit++;
                tail++;
                cbest = max(current, cbest);
            }
            cand = cbest;
        }
        bl = max(cand, bl);
    }
    return bl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }    
        cout << solve(n,k,a) << endl;
    }
    return 0;
}