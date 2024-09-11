#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(int n, int k) {
    int count = 0;
    if(n==1) return 0;
    n-=k;
    count++;
    if(n<=0) return count;
    int cand = n/(k-1);
    if(cand*(k-1) < n) count+=cand+1;
    else count += cand;
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cout << solve(n,k)<<endl;        
    }
    return 0;
}