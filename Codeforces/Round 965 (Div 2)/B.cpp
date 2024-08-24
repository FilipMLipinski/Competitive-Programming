#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> vec){
    int k = vec.size()-1;
    if(k==-1) return;
    cout << vec[k] << " ";
    for(int i = 0; i < k; ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        vector<int> vec;
        int n;
        cin >> n;
        for(int j = 0; j<n; ++j){
            int a;
            cin >> a;
            vec.push_back(a);
        }
        solve(vec);
    }
}