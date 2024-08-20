#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
long long solve(const vector<int> & a, const string & b) {
    int l = 0;
    int r = a.size() - 1;
    long long multiplier = 0;
    long long count = 0;
    // invariant: all numbers below l and above r were considered.
    while(l<r){
        while(b[l]!='L' && l<r){
            count += multiplier * a[l];
            ++l;
        }
        if(l>=r){
            break;
        }
        // b[l] == 'L'
        while(b[r]!='R' && r>l){
            count += multiplier * a[r];
            --r;
        }
        if(r<=l){
            break;
        }
        // b[r] == 'R'
        multiplier++;
        count += multiplier * (a[l]+a[r]);
        ++l;
        --r;
    }
    if(l==r) count+= multiplier * a[l];
    return count;
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
        cout << solve(a,b)<< endl;
    }
    return 0;
}