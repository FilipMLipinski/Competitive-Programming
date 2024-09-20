#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct S{
    int score;
    int outcome;
};

bool isnarek(char c){
    if(c=='n' || c=='a' || c=='r' || c=='e' || c=='k') return true;
    return false;
}

S evalstring(string plug, string s){
    s = plug + s;
    S ret;
    string query = "narek";
    int q = 0;
    int sc = plug.size();
    int furthest_i = 0;
    for(int i=0;i<s.size();i++){
        if(isnarek(s[i])) sc--;
        if(s[i]==query[q]){
            q++;
            if(q==5){
                sc+=10;
                q = 0;
                furthest_i = i+1;
            }
        }
    }
    ret.outcome = q;
    ret.score = sc;
    return ret;
}

void printV(vector<int> v){
    for(int n: v){
        cout << n << " ";
    }
    cout << endl;
}

int solve(int n, int m, vector<string> strings) {
    vector<vector<int>> dp;
    vector<string> plugs{"", "n", "na", "nar", "nare"};
    // for(string s: strings){
    //     for(int i=0;i<5;i++){
    //         cout << s + ". score:  ";
    //         S eval = evalstring(plugs[i], s);
    //         cout << eval.score << ". plug: ";
    //         cout << plugs[i] << ". outcome: ";
    //         cout << eval.outcome << endl;
    //     }
    // } 
    vector<int> zeroth = {0,-1000,-1000,-1000,-1000};
    dp.push_back(zeroth);
    for(int i=1; i<=n;i++){
        vector<int> prev = dp[i-1];
        dp.push_back(prev);
        for(int p=0; p<5; p++){
            S eval = evalstring(plugs[p], strings[i-1]);
            // cout << strings[i-1] << " ";
            // cout << "plug: " << plugs[p];
            // cout << " score: " << eval.score;
            // cout << " outcome: " << eval.outcome << endl;
            int maxoutcome = eval.outcome;
            for(int j=0;j<=maxoutcome;j++){
                int newbest = max(
                    dp[i-1][p] + eval.score,
                    dp[i-1][j]
                );
                dp[i][j] = max(newbest, dp[i][j]);
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     printV(dp[i]);
    // }
    int best = 0;
    for(int i=0;i<5;i++){
        best = max(dp[n][i], best);
    }
    return best;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> strings(n);
        for(int i=0;i<n;i++){
            cin >> strings[i];
        }
        cout << solve(n,m ,strings) << endl;
    }
    return 0;
}