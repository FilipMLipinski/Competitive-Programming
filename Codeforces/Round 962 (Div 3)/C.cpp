#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(vector<vector<int> > & mas, vector<vector<int> > & mbs, int l, int r) {
    if(l==0){
        vector<int> ma = mas[r];
        vector<int> mb = mbs[r];
        int count=0;
        for(int i=0;i<ma.size();i++){
            if(ma[i]==mb[i]) continue;
            if(ma[i] < mb[i]) count += mb[i]-ma[i];
        }
        return count;
    }
    int count = 0;
    for(int i=0;i<26;i++){
        if(mas[r][i] - mas[l-1][i] < mbs[r][i] - mbs[l-1][i]) 
            count += (mbs[r][i] - mbs[l-1][i]) - (mas[r][i] - mas[l-1][i]);
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> mas;
        vector<vector<int>> mbs;
        vector<int> ma(26, 0);
        vector<int> mb(26,0);
        for(int i=0; i<a.size();i++){
            ma[a[i] - 'a']++;
            mb[b[i] - 'a']++;
            mas.push_back(ma);
            mbs.push_back(mb);
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            cout << solve(mas, mbs, l -1,r-1) << endl;
        }        
    }
    return 0;
}