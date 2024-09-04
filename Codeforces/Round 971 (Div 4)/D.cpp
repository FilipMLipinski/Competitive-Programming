#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(vector<int> x, vector<int> y, ll n) {
    vector<int> neighof1(n+1, 0);
    vector<int> neighof0(n+1, 0);
    vector<int> count0(n+1, 0);
    vector<int> count1(n+1, 0);
    ll ret = 0;
    for(int i=0;i<n;i++){
        if(y[i]==1){
            count1[x[i]]++;
        }
        else{
            count0[x[i]]++;
        }
        if(y[i]==0){
            if(x[i]-1 >= 0) neighof1[x[i]-1]++;
            if(x[i]+1 <= n) neighof1[x[i]+1]++;
        }
        else{
            if(x[i]-1 >= 0)neighof0[x[i]-1]++;
            if(x[i]+1<=n) neighof0[x[i]+1]++;
        }
        if(count0[x[i]]==1 && count1[x[i]]==1){
            ret += n-2;
        }
    }
    for(int i=0;i<n;i++){
        if(neighof0[i] == 2 && count0[i]==1){
            ret++;
        }
        if(neighof1[i] == 2 && count1[i]==1){
            ret++;
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> y(n);
        vector<int> x(n);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        } 
        cout << solve(x,y,n) << endl;
    }
    return 0;
}