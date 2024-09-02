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

vector<int> addfreqs(vector<int> & a, vector<int> b){
    vector<int> res;
    for(int i=0;i<a.size();i++){
        res.push_back(a[i]+b[i]);
    }
    return res;
}

vector<int> subfreqs(vector<int> & a, vector<int> b){
    vector<int> res;
    for(int i=0;i<a.size();i++){
        res.push_back(a[i]-b[i]);
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
    vector<vector<int>> odds;
    vector<vector<int>> evens;
    for(int i=0;i<n;i++){
        if(i==0){
            vector<int> o(26,0);
            vector<int> e(26,0);
            o[s[i]-'a']++;
            odds.push_back(o);
            evens.push_back(e);
        }
        else{
            vector<int> o = odds[i-1];
            vector<int> e = evens[i-1];
            if(i%2){
                // i is odd = even position
                e[s[i]-'a']++;
            }
            else o[s[i]-'a']++;
            odds.push_back(o);
            evens.push_back(e);
        }
    }
    if(n%2==0){
        return n-maxcount(odds[n-1])-maxcount(evens[n-1]);
    }
    else{
        int minim = 3e5;
        for(int i=0;i<n;i++){
            if(i!=0){
                vector<int> combo = addfreqs(odds[i-1], subfreqs(evens[n-1], evens[i]));
                vector<int> combe = addfreqs(evens[i-1], subfreqs(odds[n-1], odds[i]));
                minim = min(minim, n-maxcount(combo)-maxcount(combe));
            }
            else{
                vector<int> combo = subfreqs(evens[n-1], evens[0]);
                vector<int> combe = subfreqs(odds[n-1], odds[0]);
                minim = min(minim, n-maxcount(combo)-maxcount(combe));
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