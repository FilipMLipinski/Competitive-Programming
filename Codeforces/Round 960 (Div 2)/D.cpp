#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(vector<int>& a, int n) {
    // 1-2 AND counting-false: setting counting to true;
    // 3-4 AND counting-true; count++;
    // 1-2 AND counting-true: setting counting to false; subtract 1;
    int res = 0;
    int count = 0;
    bool counting = false;
    for(int i=0;i<n;i++){
        if(a[i] <= 2 && a[i] >= 1 && !counting){
            counting = true;
        }
        else if(a[i] <= 4 && a[i]>=3 && counting){
            count++;
        }
        else if(a[i]<=2 && a[i]>=1 && counting){
            if(count%2==0){
                counting = false;
                res-=1;
            }
            count = 0;
        }
        else if((a[i]==0 || a[i]>4) && counting){
            counting = false;
            count = 0;
        }
        if(a[i]!=0){
            res++;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }        
        cout << solve(a, n) << endl;
    }
    return 0;
}