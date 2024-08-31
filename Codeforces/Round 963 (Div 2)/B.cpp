#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(vector<ll> evens, ll mxodd) {
    if(mxodd==0 || evens.size()==0) return 0;
    sort(evens.begin(), evens.end());
    int count = 0;
    ll mxeven = evens[evens.size()-1];
    for(int i = 0; i < evens.size(); i++){
        if(evens[i] < mxodd){
            count +=1;
            mxodd = evens[i] + mxodd;
        }
        else{
            mxodd = mxeven + mxodd;
            count +=2;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        ll mxodd = 0;
        vector<ll> evens;
        for(int j =0; j<n; j++){
            ll a;
            cin >> a;
            if(a%2 == 0) evens.push_back(a);
            else{
                mxodd = max(mxodd, a);
            }
        }
        cout << solve(evens, mxodd) << endl;
    }
    return 0;
}