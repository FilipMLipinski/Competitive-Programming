#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


string match(vector<int>& temp, string s){
    if(temp.size()!=s.size()) return "NO";
    unordered_map<int, char> itoc;
    unordered_map<char, int> ctoi;
    for(int i = 0; i<s.size(); ++i){
        if(itoc.count(temp[i])==0 && ctoi.count(s[i]) == 0){
            itoc.insert({temp[i], s[i]});
            ctoi.insert({s[i], temp[i]});
        } 
        else if(itoc.count(temp[i])==1 && itoc[temp[i]]!=s[i]) return "NO";
        else if(ctoi.count(s[i])==1 && ctoi[s[i]]!=temp[i]) return "NO";
    }
    return "YES";
}

int main(){
    int cases;
    cin >> cases;
    for(int i = 0; i<cases; ++i){
        int n;
        cin >> n;
        vector<int> temp;
        for(int j = 0; j<n; ++j){
            int a;
            cin >> a;
            temp.push_back(a);
        }
        int strings;
        cin >> strings;
        for(int j = 0; j<strings; ++j){
            string s;
            cin >> s;
            cout << match(temp, s) << endl;
        }
    }
    return 0;
}