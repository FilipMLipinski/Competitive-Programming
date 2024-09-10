#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(int n, int x, int y) {
    bool alt;
    if(y%2){
        alt = true;
    }
    else{
        alt = false;
    }
    for(int i=0;i<n;i++){
        if(i == y-1){
            cout << "-1 ";
        }
        else if(i==x+1){
            cout << "-1 ";
            alt = false;
        }
        else if(i <= x && y <= i){
            cout << "1 ";
        }
        else if(alt){
            cout << "-1 ";
            alt = !alt;
        }
        else{
            cout <<"1 ";
            alt = !alt;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        solve(n,x-1,y-1);
        cout << endl;
    }
    return 0;
}