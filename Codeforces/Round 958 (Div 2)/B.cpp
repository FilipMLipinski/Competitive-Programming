#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

string solve(string s, int n) {
    // compress the 0's in the string;
    // counting 1's and 0's;
    // if count1>count0, easy answer, else:
    int c1=0;
    int c0=0;
    bool lastzero = false;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(!lastzero){
                lastzero=true;
                c0++;
            }
        }
        else{
            c1++;
            lastzero=false;
        }
    }
    if(c1>c0) return "YES";
    else return "NO";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, n) << endl;        
    }
    return 0;
}