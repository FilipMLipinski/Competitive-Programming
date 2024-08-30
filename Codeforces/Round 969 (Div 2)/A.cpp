#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

int divBy(int l, int r, int c){
    int lower = (l-1)/c;
    int all = r/c;
    return all - lower;
}

int solve(int l, int r) {
    int by6 = divBy(l,r,6);
    int by2 = divBy(l,r,2);
    int by3 = divBy(l,r,3);
    int just2 = by2 - by6;
    int just3 = by3 - by6;
    int neither = r-l+1 - by2 - by3 + by6;
    int ret = min(min(just2, just3), neither);
    neither -= ret;
    just2 -= ret;
    just3 -= ret;
    int extra = 0;
    if(neither!=0){
        if(just2>1){
            extra = min(neither/2, just2);
        }
        else if(just3>1){
            extra = min(neither/2, just3);
        }
    }
    return ret + extra;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int l, r;
        cin >> l >> r;
        cout << solve(l,r) << endl;
    }
    return 0;
}