#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solve(vector<int> a) {
    // TODO: edit here
    if(a.size()>2){
        return false;
    }
    else if(a.size()==1){
        return true;
    }
    else{
        return (abs(a[0]-a[1])!=1);
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j<n; j++){
            cin >>a[j];
        }
        if(solve(a)){
            cout << "Yes"<<endl;
        }
        else{
            cout <<"no"<<endl;
        }
    }
    return 0;
}