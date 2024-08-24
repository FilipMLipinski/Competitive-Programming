#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
bool solve(const vector<int> & a, int s, int m) {
    int last = 0;
    int i = 0;
    while(i<a.size()){
        if(a[i] - last >= s) return true;
        ++i;
        last = a[i];
        ++i;
    }
    if(m - last >= s) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        string s;
        string t;
        vector<int> intervals(2*n);
        REP(j, n){
            int l, r;
            cin >> l >> r;
            intervals[2*j] = l;
            intervals[2*j+1] = r;
        }
        cout << (solve(intervals, s, m) ? "YES":"NO") << endl;
    }
    return 0;
}