#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";
void solve(int n) {
    string result = "!";
    for(int i=n; i>1; --i){
        bool found = false;
        int higher = 1;
        // finding the parent of i
        while(!found){
            cout << "? " << i << " " << higher << endl;
            int temp;
            cin >> temp;
            if(temp==i){
                found = true;
                result += " " + to_string(i) + " " + to_string(higher);
            }
            higher = temp;
        }
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}