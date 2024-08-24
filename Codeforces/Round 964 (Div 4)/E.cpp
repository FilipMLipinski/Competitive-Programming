#include <string>
#include <vector>
#include <iostream>
#include <cmath>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";

int min3(int l){
    int count = 0;
    while(l>0){
        l = l/3;
        count++;
    }
    return count;
}

int solve(int l, int r) {
    // TODO: edit here
    int total = 0;
    int current = min3(l);
    total += current * 2;
    // by now the first number is 0, the rest is [l+1, r];
    int next_checkpoint = pow(3, (current));
    for(int x = l+1; x<=r; x++){
        //cout << "x: " << x << " next checkpoint: " << next_checkpoint << " current: " << current << endl;
        if(x<next_checkpoint){
            total += current;
        }
        else{
            current += 1;
            total += current;
            next_checkpoint = pow(3, (current));
        }
    }
    return total;

}

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        int l, r;
        cin >> l >> r;
        cout << solve(l,r) << endl;
    }
    return 0;
}