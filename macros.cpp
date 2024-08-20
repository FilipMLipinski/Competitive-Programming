#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
bool solve(const vector<int> & a, string & b) {
    // TODO: edit here
}

int main() {
    int n;
    cin >> n;
    REP (i, n) {
        int k;
        cin >> k;
        vector<int> a(k);
        REP(j, k){
            cin >> a[j];
        }
        string b;
        cin >> b;
        cout << (solve(a,b) ? "YES":"NO") << endl;
    }
    return 0;
}