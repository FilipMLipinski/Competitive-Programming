#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int minstepsto(int k, pair<int, int> p){
    int a = p.first;
    int b = p.second;
    if(k==a+b){
        return a*b;
    }
    if(k>a+b) return INT_MAX;
    int count = 0;
    while(k!=0 && a>0 && b>0){
        if(a<b){
            count+=a;
            b-=1;
        }
        else{
            count += b;
            a-=1;
        }
        k-=1;
    }
    if(k==0) return count;
    else return INT_MAX;
}

int solve(int n, int k, vector<pair<int, int>> & s) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    dp[1][1] = minstepsto(1, s[0]);
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            int best = dp[i-1][j];
            for(int r=1;r<j;r++){
                if(minstepsto(r, s[i-1])!=INT_MAX && dp[i-1][j-r]!=INT_MAX){
                    best = min(best, minstepsto(r, s[i-1])+dp[i-1][j-r]);
                }
            }
            best = min(best, minstepsto(j, s[i-1]));
            dp[i][j] = best;
        }
    }
    int ret = dp[n][k];
    if(ret==INT_MAX) return -1;
    else return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n ,k;
        cin >> n>>k;
        vector<pair<int, int>> s;
        for(int i=0;i<n;i++){
            int a, b;
            cin >>a>>b;
            s.push_back({a, b});
        }
        cout << solve(n,k,s) << endl;
    }
    return 0;
}