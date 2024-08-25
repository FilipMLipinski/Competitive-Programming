#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const string YES = "YES";
const string NO = "NO";
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int i = -1;
    int j = a.size()-1;
    // invariant (i, j] hasnt been removed yet
    while(i+1!=j){
        ++i;
        if(i+1==j){
            return a[j];
        }
        --j;
    }
    return a[j];
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t;i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j =0; j<n;j++){
            cin >> a[j];
        }
        cout << solve(a) << endl;
    }
    return 0;
}