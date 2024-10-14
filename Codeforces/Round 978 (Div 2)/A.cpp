#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(int n, int r, int *a) {
    int happy = 0;
    int mis = 0;
    for(int i=0;i<n;i++){
        r -= a[i]/2;
        happy += (a[i]/2) * 2;
        if(a[i]%2 == 1) mis++;
    }
    if(r < mis) happy += 2*r - mis;
    else happy += mis;
    return happy;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        int a[n]; 
        for(int i=0;i<n;i++){
           cin >> a[i]; 
        }        
        cout << solve(n,r,a) << endl;
    }
    return 0;
}