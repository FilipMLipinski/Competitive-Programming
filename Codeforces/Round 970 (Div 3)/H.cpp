#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool ismedlessthan(vector<int> & p, int m, int x, int n){
    // count elements in [0, m] + [x, x+m], [2x, 2x+m] ... [(n-1/x)x, (n-1/x)x + m]
    int count = 0;
    count += p[min(m, n-1)];
    int i = 1;
    while(i*x<=n){
        count += p[min(n, x*i+m)] - p[x*i-1];
        i++;
    }
    return count > n/2;
}

void printV(vector<int> v){
    for(int i: v){
        cout << i << " ";
    }
    cout << endl;
}

string solve(vector<int> & p, vector<int> & q, int n) {
    for(int i=1;i<=n;i++){
        p[i]+=p[i-1];
    }
    string ret;
    vector<int> preq(n+1, -1);
    for(int i=0;i<q.size();i++){
        if(preq[q[i]]!=-1){
            ret += to_string(preq[q[i]]) + " ";
            continue;
        }
        int s = -1;
        int e = q[i];
        // the smallest median is in (s,e]
        while(s+1!=e){
            int m = (s+e)/2;
            if(ismedlessthan(p,m,q[i],n)){
                e = m;
            }
            else{
                s = m;
            }
        }
        preq[q[i]] = e;
        ret += to_string(e) + " ";
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1, 0);
        vector<int> qs(q);
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            p[a]++;
        }
        for(int i =0;i<q;i++){
            cin >> qs[i];
        }
        cout << solve(p, qs, n) << endl;
    }
    return 0;
}