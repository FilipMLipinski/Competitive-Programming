#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool solve(int o, int t) {
    if(o==0) return t%2==0;
    if(o%2) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
       int o,t;
       cin >> o >> t;
       if(solve(o,t)) cout << "YES"<<endl;
       else cout <<"NO"<<endl;
    }
    return 0;
}