#include <string>
#include <vector>
#include <iostream>
using namespace std;

string isImp(string s){
    int n = s.size();
    if(n<3) return "NO";
    if(s.substr(0,2)!="10") return "NO";
    if(s.substr(0,3)=="100") return "NO";
    if(n==3 && s[2]=='1') return "NO";
    else return "YES";
}

int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i<n; ++i){
        cin >> s;
        cout << isImp(s) << endl;
    }
    return 0;
}

