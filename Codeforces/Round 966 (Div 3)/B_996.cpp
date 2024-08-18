#include <string>
#include <vector>
#include <iostream>
using namespace std;

string followed(vector<int> a){
    int i = a[0], j = a[0];
    for(int c = 1; c<a.size(); ++c){
        if(a[c] == i-1) --i;
        else if(a[c] == j+1) ++j;
        else return "NO";
    }
    return "YES";
}

int main(){
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; ++i){
        int n;
        cin >> n;
        vector<int> as;
        for(int j = 0; j<n; ++j){
            int c;
            cin >> c;
            as.push_back(c);
        }
        cout << followed(as) << endl;
    }
    return 0;
}