#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool solve(string m) {
    int first_o = -1;
    for(int i=0;i<m.size();i++){
        if(m[i] == '0'){ 
            first_o = i-1;
            break;
        }
    }
    if(first_o == -1) return m.size()==4;
    // check if the matrix is closed;
    int b = first_o;
    int r = m.size()/b;
    if(m[r]=='1'){
        //matrix is closed;
        return r==b;
    }
    else{
        //matrix is open;
        return r+1<=b;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string m;
        int n;
        cin >> n;
        cin >> m;
        if(solve(m)) cout << "YES" <<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}