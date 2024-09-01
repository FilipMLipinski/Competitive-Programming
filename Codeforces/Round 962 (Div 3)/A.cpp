#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(int l) {
    int cows = l/4;
    int chicks = l%4 / 2;
    return cows+chicks;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        cout << solve(l) << endl;        
    }
    return 0;
}