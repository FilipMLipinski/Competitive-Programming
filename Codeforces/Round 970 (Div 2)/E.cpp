#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int maxcount(vector<int> & a){
    int res = 0;
    for(int i: a){
        res = max(res,i);
    }
    return res;
}

vector<int> addfreqs(vector<int> & a, vector<int> & b){
    vector<int> res;
    for(int i=0;i<a.size();i++){
        res.push_back(a[i]+b[i]);
    }
    return res;
}

void printV(vector<int> v){
    for(int i: v){
        cout << i << " ";
    }
    cout << endl;
}

int solve(string s, int n) {
    if(n==1) return 1;
    if(n%2 ==0){
        vector<int> evens(26, 0);
        vector<int> odds(26, 0);
        for(int i=0;i<n;i++){
            if(i%2){
                evens[s[i]-'a']++;
            }
            else{
                odds[s[i]-'a']++;
            }
        }
        int eve = 0;
        int odd = 0;
        for(int i=0;i<26;i++){
            eve = max(eve, evens[i]);
            odd = max(odd, odds[i]);
        }
        return n - eve - odd;
    }
    else{
        vector<vector<int>> eb;
        vector<vector<int>> ef;
        vector<vector<int>> ob;
        vector<vector<int>> of;
        for(int i=0;i<n;i++){
            if(i==0){
                vector<int> odds(26, 0);
                vector<int> evens(26, 0);
                odds[s[i]-'a']++;
                ob.push_back(odds);
                eb.push_back(evens);
            }
            else if(i%2==0){
                vector<int> odds = ob[i-1];
                vector<int> evens = eb[i-1];
                odds[s[i]-'a']++;
                ob.push_back(odds);
                eb.push_back(evens);
            }
            else{
                vector<int> odds = ob[i-1];
                vector<int> evens = eb[i-1];
                evens[s[i]-'a']++;
                ob.push_back(odds);
                eb.push_back(evens);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                vector<int> odds(26,0);
                vector<int> evens(26,0);
                evens[s[i]-'a']++;
                of.push_back(odds);
                ef.push_back(evens);
            }
            else{
                vector<int> odds = of[n-i-2];
                vector<int> evens = ef[n-i-2];
                if(i%2){
                    odds[s[i]-'a']++;
                }
                else{
                    evens[s[i]-'a']++;
                }
                of.push_back(odds);
                ef.push_back(evens);
            }
        }
        int minim = 3e5;
        //cout << "hello"<<endl;
        for(int i=0;i<n;i++){
            if(i==0){
                // cout << "i: "<<i<<endl;
                // printV(of[n-2]);
                // printV(ef[n-2]);
                minim = min(n - maxcount(of[n-2]) - maxcount(ef[n-2]), minim);
            }
            else if(i==n-1){
                // cout << "i: " << i<<endl;
                // printV(ob[n-2]);
                // printV(eb[n-2]);
                minim = min(n-maxcount(ob[n-2])-maxcount(eb[n-2]), minim);
            }
            else{
                vector<int> o = addfreqs(ob[i-1], of[n-i-2]);
                vector<int> e = addfreqs(eb[i-1], ef[n-i-2]);
                // cout << "i: " << i<<endl;
                // printV(ob[i-1]);
                // printV(ef[n-i-2]);
                // printV(eb[i-1]);
                // printV(of[n-i-2]);
                // printV(o);
                // printV(e);
                int podds = maxcount(o);
                int pevens = maxcount(e);
                // cout << "result: " << n-podds-pevens<<endl;
                minim = min(n-podds-pevens,minim);
            }
        }
        return minim;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        string s;
        cin >> s;
        cout << solve(s, n) <<endl; 
    }
    return 0;
}