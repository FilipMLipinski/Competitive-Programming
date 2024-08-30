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
    int size = r-l+1;
    if(size < 3) return 0;
    if(size == 3){
        if(l%2 == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(size%4 == 3){
        if(l%2 == 1){
            return 1 + (size-3)/4;
        }
        else{
            return (size-3)/4;
        }
    }
    else{
        return size/4;
    }
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