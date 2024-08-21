#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
void solve(int k) {
    if(k==1) cout<<1;
    else if(k%2==0) cout<<-1; 
    else{
        int m = (k-1)/2;
        for(int i = 1; i<=m;++i){
            cout<<i<< " ";
        }
        for(int i = k; i>m; --i){
            cout<<i<< " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    REP (i, n) {
        int k;
        cin >> k;
        solve(k);
        cout << endl;
    }
    return 0;
}