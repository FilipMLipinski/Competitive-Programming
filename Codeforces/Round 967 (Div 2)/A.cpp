#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
int solve(int n, const vector<int> & a) {
    unordered_map<int, int> map;
    int max_rep = 0;
    REP(i, n){
        if(map.count(a[i])==0) map[a[i]] = 1;
        else map[a[i]] += 1;
        max_rep = max(max_rep, map[a[i]]);
    }
    return n - max_rep;
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
        cout << solve(k, a) << endl;
    }
    return 0;
}