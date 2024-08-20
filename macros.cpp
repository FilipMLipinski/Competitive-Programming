#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
bool solve(int n, const vector<int> & a, const vector<int> & b) {
    // TODO: edit here
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP (i, n) {
        cin >> a[i] >> b[i];
    }
    auto ans = solve(n, a, b);
    cout << (ans ? YES : NO) << endl;
    return 0;
}