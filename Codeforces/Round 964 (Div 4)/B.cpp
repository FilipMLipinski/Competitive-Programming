#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";

int solve(int s1, int s2, int b1, int b2) {
    int count = 0;
    if((s1>b2 && s2>=b1) || (s1>=b2 && s2>b1)){
        count+=2;
    }
    if((s1>b1 && s2>=b2) || (s1>=b1 && s2>b2)) {
        count+=2;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        int s1, s2, b1, b2;
        cin >> s1 >> s2 >> b1 >> b2;
        cout << (solve(s1, s2, b1, b2)) << endl;
    }
    return 0;
}