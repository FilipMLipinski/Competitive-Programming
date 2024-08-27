#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

int solve(int l, int L, int r, int R) {
    if(L < l){
        if(R<l){
            return 1;
        }
        if(r<R){
            return r-l+2;
        }
        if(r==R){
            return r-l+1;
        }
        if(R<r){
            return R-l+2;
        }
    }
    if(l<L){
        if(r<L){
            return 1;
        }
        if(r<R){
            return r-L+2;
        }
        if(R<r){
            return R-L+2;
        }
        if(R==r){
            return R-L+1;
        }
    }
    if(l==L){
        if(r==R){
            return r-l;
        }
        else{
            return min(r,R) - l + 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int l, L, r, R;
        cin>>l >>L>>r>>R;
        cout << solve(l,r, L, R) << endl;
    }
    return 0;
}