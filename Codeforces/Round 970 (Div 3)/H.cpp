#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool medlesseqthan(vector<int> & a, int x){
    int count = 0;
    for(int i=0; i<a.size();i++){
        if(a[i]<=x) count++;
    }
    return count > a.size()/2;
}

int solve(vector<int> a, int x) {
    int n = a.size();
    for(int i=0;i<n;i++){
        a[i] = (a[i])%x;
    }
    int s = -1;
    int e = n;
    // the median is in (s, e]
    int i = 5;
    while(s+1!=e){
        int m = (s+e)/2;
        if(medlesseqthan(a, m)){
            e = m;
        }
        else{
            s = m;
        }
    }
    return e;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<int> ret(q);        
        for(int i =0;i<q;i++){
            int x;
            cin >> x;
            ret[i] = solve(a, x);
        }
        for(int i=0;i<q;i++){
            cout << ret[i] << " ";
        }
        cout << endl;
    }
    return 0;
}