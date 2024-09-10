#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(int a, int b, int c) {
    for(int i=0;i<5;i++){
        if(a<=b && a<=c) a++;
        else if (b<=a && b<=c) b++;
        else if(c<=a && c<=b) c++;
    }
    return a*b*c;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        cout << solve(a,b,c) << endl;
    }
    return 0;
}